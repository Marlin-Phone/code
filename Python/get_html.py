import requests
from urllib.robotparser import RobotFileParser
from bs4 import BeautifulSoup
from urllib.parse import urljoin
import time
import os
import re

# 配置参数
BASE_URL = "http://xcb.www.sust.edu.cn/llyd.htm"
SAVE_DIR = "sust_knowledge"
HEADERS = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36",
    "Accept-Language": "zh-CN,zh;q=0.9"
}
DELAY = 5  # 增加延迟时间
MAX_DEPTH = 1  # 最大抓取深度
TIMEOUT = 15
FILENAME_MAX_LENGTH = 50

visited_urls = set()
allowed_domains = ['sust.edu.cn']


def save_content(url, content):
    """增强版文件保存函数"""
    if not os.path.exists(SAVE_DIR):
        os.makedirs(SAVE_DIR)

    # 文件名清洗逻辑
    filename = url.split('?')[0]  # 去除查询参数
    filename = re.sub(r'[\\/:*?"<>|]', '_', filename)  # 替换非法字符[1](@ref)
    filename = filename.replace('https://', '').replace('http://', '')
    filename = filename.replace('/', '_')[:FILENAME_MAX_LENGTH]  # 控制长度[1](@ref)
    filename = filename.strip('_') + '.txt'  # 处理边界下划线

    # 路径安全处理
    filename = os.path.basename(filename)
    filepath = os.path.join(SAVE_DIR, filename)

    try:
        with open(filepath, 'w', encoding='utf-8') as f:
            f.write(f"URL: {url}\n\n")
            f.write(content)
        print(f"成功保存: {filename}")
    except (OSError, IOError) as e:
        print(f"文件保存失败: {e} | 文件名: {filename}")

def check_robots(url):
    """检查robots协议"""
    rp = RobotFileParser()
    rp.set_url(urljoin(url, "/robots.txt"))
    try:
        rp.read()
        return rp.can_fetch("*", url)
    except Exception as e:
        print(f"无法获取robots.txt: {str(e)}")
        return True


def is_valid_url(url):
    """验证是否为有效内部链接"""
    if not url.startswith(('http://', 'https://')):
        url = urljoin(BASE_URL, url)
    return any(domain in url for domain in allowed_domains) \
        and not url.endswith(('.pdf', '.doc', '.docx', '.jpg')) \
        and '#' not in url


def fetch_page(url):
    """抓取页面内容"""
    try:
        response = requests.get(url, headers=HEADERS, timeout=TIMEOUT)
        response.raise_for_status()
        response.encoding = response.apparent_encoding  # 自动检测编码
        return response.text
    except Exception as e:
        print(f"抓取失败: {url} | 错误: {str(e)}")
        return None


def sanitize_url(url):
    """URL标准化处理"""
    parsed = urlparse(url)
    # 保留必要查询参数
    allowed_params = ['id', 'page']
    query = parse_qs(parsed.query)
    filtered_query = {k: v for k, v in query.items() if k in allowed_params}

    return urlunparse((
        parsed.scheme,
        parsed.netloc,
        parsed.path,
        parsed.params,
        urlencode(filtered_query, doseq=True),
        parsed.fragment
    ))

def extract_links(html, base_url):
    """提取站内链接"""
    soup = BeautifulSoup(html, 'html.parser')
    links = []
    for a in soup.find_all('a', href=True):
        href = a['href']
        full_url = urljoin(base_url, href)
        if is_valid_url(full_url):
            links.append(full_url)
    return list(set(links))


def clean_content(html):
    """清洗高校官网内容"""
    soup = BeautifulSoup(html, 'html.parser')

    # 移除通用元素
    for tag in ['script', 'style', 'header', 'footer', 'nav', 'iframe']:
        for element in soup.find_all(tag):
            element.decompose()

    # 针对高校网站的特殊处理
    main_content = soup.find('div', class_=['content', 'main', 'article']) \
                   or soup.find('div', id=['content', 'container', 'main'])

    if main_content:
        # 清理不需要的子元素
        for cls in ['sidebar', 'comment', 'advertisement']:
            for element in main_content.find_all(class_=cls):
                element.decompose()
        return main_content.get_text(separator='\n', strip=True)

    return soup.get_text(separator='\n', strip=True)





def crawler(url, depth=0):
    if depth > MAX_DEPTH or url in visited_urls:
        return

    if not check_robots(url):
        print(f"被robots.txt禁止访问: {url}")
        return

    print(f"正在抓取: {url}")
    visited_urls.add(url)

    html = fetch_page(url)
    if not html:
        return

    # 保存主要内容
    cleaned = clean_content(html)
    save_content(url, cleaned)

    # 提取并递归抓取链接
    if depth < MAX_DEPTH:
        links = extract_links(html, url)
        for link in links:
            if link not in visited_urls:
                time.sleep(DELAY)
                crawler(link, depth + 1)


if __name__ == "__main__":
    if check_robots(BASE_URL):
        crawler(BASE_URL)
    else:
        print("根据robots协议，禁止抓取该网站")
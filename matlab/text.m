% 读取数据
medal_counts = readtable('summerOly_medal_counts.csv');
hosts = readtable('summerOly_hosts.csv');
programs = readtable('summerOly_programs.csv');
athletes = readtable('summerOly_athletes.csv');

% 数据清洗
medal_counts = rmmissing(medal_counts); % 删除缺失值
medal_counts = unique(medal_counts); % 删除重复值

hosts = rmmissing(hosts);
hosts = unique(hosts);

programs = rmmissing(programs);
programs = unique(programs);

athletes = rmmissing(athletes);
athletes = unique(athletes);

% 计算总奖牌数
medal_counts.TotalMedals = medal_counts.Gold + medal_counts.Silver + medal_counts.Bronze;

% 创建主办国效应特征
medal_counts.HostEffect = ismember(medal_counts.Year, hosts.Year);

% 合并数据集
data = join(medal_counts, hosts, 'Keys', 'Year');
data = join(data, programs, 'Keys', 'Year');

% 将数据分为训练集和测试集
trainData = data(data.Year < 2024, :); % 训练集
testData = data(data.Year == 2024, :); % 测试集

% 选择特征和目标变量
X_train = [trainData.Gold, trainData.Silver, trainData.Bronze, trainData.HostEffect];
y_train = trainData.TotalMedals;

% 训练线性回归模型
model = fitlm(X_train, y_train);

% 选择测试集特征
X_test = [testData.Gold, testData.Silver, testData.Bronze, testData.HostEffect];

% 进行预测
y_pred = predict(model, X_test);

% 结果展示
disp('预测结果:');
disp(y_pred);

% 计算预测的置信区间
ci = coefCI(model);
disp('置信区间:');
disp(ci);

% 分析表现可能改善或下降的国家
improvedCountries = testData.NOC(y_pred > testData.TotalMedals);
worseCountries = testData.NOC(y_pred < testData.TotalMedals);

disp('表现可能改善的国家:');
disp(improvedCountries);

disp('表现可能下降的国家:');
disp(worseCountries);

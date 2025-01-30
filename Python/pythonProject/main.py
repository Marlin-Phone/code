import pandas as pd
from sklearn.linear_model import BayesianRidge
from sklearn.model_selection import train_test_split
from sklearn.metrics import mean_absolute_error
import matplotlib.pyplot as plt

# Set font to SimHei (or other fonts that support Chinese)
plt.rcParams['font.sans-serif'] = ['SimHei']  # Display Chinese characters using SimHei font
plt.rcParams['axes.unicode_minus'] = False  # Solve the issue of displaying minus sign

# Load TrainingData
file_path = "./TrainingData.csv"
training_data = pd.read_csv(file_path)

# Hypothetical coach data
coach_data = pd.DataFrame({
    "Coach": ["Lang Ping", "Béla Károlyi", "Great Coach A"],
    "Country": ["China", "USA", "Romania"],
    "Sport": ["Volleyball", "Gymnastics", "Gymnastics"],
    "Year_Start": [2000, 1984, 1976],
    "Year_End": [2008, 2000, 1992],
    "ImpactFactor": [5, 4, 3]  # Preset impact strength of the coach on medals
})

# Add sport data (assumed based on known TrainingData)
training_data["Sport"] = training_data["NOC"].map({
    "CHN": "Volleyball",
    "USA": "Gymnastics",
    "ROM": "Gymnastics"
}).fillna("Unknown")  # Fill unknown sports as "Unknown"

# Add coach effect
def calculate_coach_effect(row):
    for _, coach in coach_data.iterrows():
        if (row["NOC"] == coach["Country"]) and \
           (row["Sport"] == coach["Sport"]) and \
           (coach["Year_Start"] <= row["Year"] <= coach["Year_End"]):
            return coach["ImpactFactor"]
    return 0  # No coach effect

training_data["CoachEffect"] = training_data.apply(calculate_coach_effect, axis=1)

# Prepare features and target variable
features = ["Year", "PersonTimes", "GenderRatio", "EliteCount", "LastBronze", "LastSilver", "LastGold", "LastTotal", "CoachEffect"]
target = "Total"

X = training_data[features]
y = training_data[target]

# Split data
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Use Bayesian Ridge model
model = BayesianRidge()
model.fit(X_train, y_train)

# Predict results
y_pred = model.predict(X_test)

# Model evaluation
mae = mean_absolute_error(y_test, y_pred)
print(f"Mean Absolute Error (MAE): {mae:.2f}")

# Coach effect contribution
coefficients = model.coef_
coach_effect_contribution = coefficients[-1]
print(f"Average contribution of coach effect to total medal count: {coach_effect_contribution:.2f} medals")

# Visualize actual vs predicted values
plt.figure(figsize=(10, 6))
plt.scatter(y_test, y_pred, alpha=0.7, color="blue", label="Predicted vs Actual")
plt.plot([y_test.min(), y_test.max()], [y_test.min(), y_test.max()], color="red", linestyle="--", label="Ideal Prediction")
plt.xlabel("Actual Medal Count")
plt.ylabel("Predicted Medal Count")
plt.legend()
plt.title("GC-MC Model Prediction Results")
plt.show()
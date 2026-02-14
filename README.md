# State-of-Charge (SOC) Estimation of Li-Ion Batteries using Extended Kalman Filter (EKF)

## 📌 Project Overview
This repository contains a closed-loop Battery Management System (BMS) simulation built in MATLAB/Simulink. The project accurately estimates the State-of-Charge (SOC) of a Lithium-Ion cell under dynamic load conditions by fusing Coulomb Counting with Voltage feedback using an Extended Kalman Filter (EKF).

**Production-ready C code was automatically generated from this model using Simulink Coder, demonstrating a complete Model-Based Design (MBD) workflow.**

## ⚙️ Key Features
* **Plant Modeling:** 1st-order Equivalent Circuit Model (ECM) simulating OCV hysteresis, internal resistance, and RC polarization dynamics.
* **EKF Algorithm:** A custom-built non-linear state observer that self-corrects SOC estimates based on real-time voltage sensor feedback.
* **Robust Convergence:** Successfully demonstrated the algorithm's ability to correct a massive **50% initial SOC initialization error** to within 5% accuracy in under 20 seconds.
* **Embedded-Ready Code:** Includes auto-generated C/C++ code ready for deployment to a microcontroller.

## 📊 Results & Performance
The filter was intentionally stress-tested with a completely wrong initial guess (Algorithm started at 50% SOC, while the physical plant was at 100% SOC). 

*As shown in the scope output below, the EKF instantly detects the voltage mismatch and snaps the estimated SOC (Blue) to the True SOC (Yellow) in seconds, ensuring stable tracking as the battery discharges.*

![EKF Convergence Graph](image_b1f980.png)

## 🛠️ The Math (State-Space Architecture)
The EKF handles the non-linear relationship between SOC and OCV (Open Circuit Voltage). The algorithm relies on two tuned Kalman gains:
1. **SOC Gain (0.5):** Dictates how aggressively the filter trusts the voltage sensor to correct the charge estimate.
2. **Polarization Voltage Gain (-0.1):** Provides negative feedback to stabilize the internal RC lag calculation, preventing mathematical divergence.

## 🚀 How to Run
1. Clone this repository.
2. Open the `.slx` file in MATLAB/Simulink.
3. Run the simulation.
4. Open the `SOC_Comparison` scope to view real-time convergence.
5. Inspect the generated `.c` and `.h` files to view the embedded C code.

## 💻 Tech Stack
* MATLAB / Simulink
* Simulink Coder (C/C++ Code Generation)
* Control Systems / Estimation Theory

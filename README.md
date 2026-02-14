# Lithium-Ion BMS: SOC Estimation using Extended Kalman Filter

## Project Overview
This repository contains a closed-loop Battery Management System (BMS) simulation developed in MATLAB/Simulink. The primary objective is to accurately estimate the State-of-Charge (SOC) of a Li-Ion cell under dynamic load by fusing Coulomb Counting (current integration) with Voltage feedback via an Extended Kalman Filter (EKF). 

To demonstrate a complete Model-Based Design (MBD) workflow, production-ready embedded C code was generated directly from the Simulink model using Simulink Coder.

## System Architecture

### 1. Plant Modeling (Digital Twin)
The physical battery is simulated using a 1st-order Equivalent Circuit Model (ECM). 
* **State-of-Charge & OCV:** A 1-D Lookup Table is utilized to map the non-linear relationship between the battery's SOC and its Open Circuit Voltage (OCV).
* **Dynamic Response:** The model captures instantaneous voltage drops via Ohmic internal resistance ($R_0$) and simulates chemical diffusion lag using an RC polarization network ($R_1$, $C_1$).

### 2. State Observer Design (EKF)
A non-linear state observer was designed to correct SOC drift caused by sensor noise and integration errors. 
* **Measurement Update:** The EKF compares the plant's actual terminal voltage against the internal model's predicted voltage.
* **Correction Logic:** The resulting residual error is multiplied by tuned Kalman gains to continually update the state vector (SOC and Polarization Voltage).

## Simulation Results: Convergence Validation
To validate the robustness of the observer, the algorithm was stress-tested using a massive initialization mismatch. 
* **Initial Conditions:** The physical plant was initialized at 100% SOC, while the EKF algorithm was deliberately initialized at 50% SOC.
* **Performance:** As shown in the scope data below, the observer instantly detects the voltage discrepancy and converges to the true SOC within 20 seconds. Post-convergence, the filter maintains stable, high-fidelity tracking throughout the discharge cycle.

![EKF Convergence Graph](SOC Comaparison.png)

## Filter Tuning Parameters
* **SOC Gain ($K_{soc}$):** Set to `0.5` to prioritize rapid convergence and aggressively correct initial sensor blindness.
* **Polarization Voltage Gain ($K_v$):** Set to `-0.1` to provide necessary negative feedback, stabilizing the internal RC lag calculation and preventing mathematical divergence in the closed loop.

## Repository Structure
* `SOC_Estimation_using_kalman_filter.slx`: The primary Simulink model containing the plant and observer.
* `_grt_rtw/`: Directory containing the auto-generated C/C++ source code and header files for microcontroller deployment.

## How to Run
1. Clone this repository.
2. Open the `.slx` file in MATLAB/Simulink.
3. Run the simulation.
4. Open the `SOC_Comparison` scope to view real-time convergence.
5. Inspect the generated `.c` and `.h` files to view the embedded C code.

## Tech Stack
* MATLAB / Simulink
* Simulink Coder (C/C++ Code Generation)
* Control Systems / Estimation Theory

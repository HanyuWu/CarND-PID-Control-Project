# CarND-PID-Control-Project
## Write-Up
----------------------------
* **Compilation**<br>  

Src codes and Cmake are all set in the repository, the simulation tool can be found [**here**](https://github.com/udacity/self-driving-car-sim/releases)&nbsp;.<br>

* **Implementation**<br>

I simply used a PID controller to control the input to the plant (car). All three states are available (CTE, derivative of CTE, and integral of CTE), and constitute the feedback in the system. 

* **Reflection**<br>

In this simulation, steering angle should be between -1 and 1, which means we can't make P,I,D components too large.<br> 

P component can pull back the car on the track when CTE is non-zero. Increasing the proportional gain &nbsp; <img src="https://latex.codecogs.com/svg.latex?K_{p}" title="K_{p}" /> &nbsp; has the effect of proportionally increasing the control signal for the same level of error. The fact that the controller will "push" harder for a given level of error tends to cause the closed-loop system to react more quickly, but also to overshoot more. Another effect of increasing $K_p$ is that it tends to reduce, but not eliminate, the steady-state error. We don't like the system overshoot a lot in this system, cause the input has its limit (-1 to 1).<br>

The addition of a derivative term to the controller &nbsp;<img src="https://latex.codecogs.com/svg.latex?K_{d}" title="K_{d}" /> &nbsp; adds the ability of the controller to "anticipate" error. With simple proportional control, if &nbsp; <img src="https://latex.codecogs.com/svg.latex?K_{p}" title="K_{p}" /> &nbsp; is fixed, the only way that the control will increase is if the error increases. With derivative control, the control signal can become large if the error begins sloping upward, even while the magnitude of the error is still relatively small. This anticipation tends to add damping to the system, thereby decreasing overshoot. The addition of a derivative term, however, has no effect on the steady-state error. So in this project, I would like to set &nbsp;<img src="https://latex.codecogs.com/svg.latex?K_{d}" title="K_{d}" /> &nbsp; to a relatively large value to suppress the possible overshoot.<br>

The addition of an integral term to the controller &nbsp;<img src="https://latex.codecogs.com/svg.latex?K_{i}" title="K_{i}" /> &nbsp; tends to help reduce steady-state error. If there is a persistent, steady error, the integrator builds and builds, thereby increasing the control signal and driving the error down. A drawback of the integral term, however, is that it can make the system more sluggish (and oscillatory) since when the error signal changes sign, it may take a while for the integrator to "unwind." Additionally, &nbsp;<img src="https://latex.codecogs.com/svg.latex?K_{i}" title="K_{i}" /> &nbsp; can increase the overshoot in the system too. In this project, our implementation of &nbsp;<img src="https://latex.codecogs.com/svg.latex?K_{i}" title="K_{i}" /> &nbsp; can make the car stay in the middle of the track.<br>

In my project, I set the PID parameters as follows:<br>

| Kp     | Kd   |  Ki  |
|  ----  | ---- | ---- |
|   0.2  | 12   | 0.02 |<br>

A snippet of my simulation is as follows:<br>
<div align="center">
<img src="examples/visual_aids.gif"/>
</div>

Ｉ tune my PID parameter simply by manual tuning. I watch how it perform in the simulation then fine tune the PID components. In fact, some extra help can be found [**here**](http://ctms.engin.umich.edu/CTMS/index.php?example=Introduction&section=ControlPID). It gives me some intuition about how I should tune PID, according to the performance I want.<br>


* **Simulation**<br>

Overall performance is acceptable, as no tire leave the drivable portion of the track surface. The car does not pop up onto ledges or roll over any surfaces that would otherwise be considered unsafe.<br>

* **Further improvment**<br>

I think I only implement a very simple controller with No input (can be speed), no feedfoward term, no control for the noise (the changing environment). I think I can do something more to improve the controllers, because the car in the simulation wiggle all the time. I think it's because the noise adding to the system. To get rid of this, silde mode control or other advanced control(RISE controller I think) methods can be considered.<br>

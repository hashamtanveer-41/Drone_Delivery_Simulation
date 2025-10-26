# Delivery Drone Simulator

## Title and Team Information

**Project Title:** Delivery Drone Simulator

**Team Members:**
- M Hamza - Logic Designer & Programmer
- M Asfand Khan - Tester
- Hasham Tanveer - Git Manager

## Overview / Problem Description

This program simulates a delivery drone system that attempts to complete delivery missions while dealing with real-world challenges. The drone has to navigate through different weather conditions, avoid obstacles, and manage its battery level to successfully deliver packages.

This problem is interesting because it mirrors real-world scenarios that autonomous delivery systems face today. Companies are increasingly investing in drone delivery technology, and understanding how to handle unpredictable environmental factors and resource management is crucial for making these systems reliable and practical.

## Program Design / Logic

The program implements the following functions:

- **`operationDecider()`** - Determines the outcome of each delivery mission based on weather conditions, obstacle detection, and battery level
- **`deliveryResults()`** - Displays the result of each delivery attempt and updates mission statistics
- **`BatteryUpdate()`** - Manages the drone's battery consumption based on mission outcomes

### How the Logic Flows

After the simulation starts, the program runs three delivery missions. For each mission, the `operationDecider()` function is called to check the current conditions. This function evaluates whether the drone has enough battery, checks the weather status, and determines if any obstacles are present. Based on these factors, it returns a mission status (Success, Fail, Delay, or Recharge). The `deliveryResults()` function then processes this status and updates the global counters. Finally, `BatteryUpdate()` adjusts the battery level according to what happened during the mission.

### Random Environmental Simulation

Random environmental factors are simulated using the `rand()` function. Weather conditions are randomly selected from three options (sunny, rainy, or windy), and obstacle presence is determined randomly with a 50% probability. The battery starts at 100% and decreases or increases based on mission outcomes.


## Execution Instructions

### Sample Output
```
-------------------------------------
| Drone delivery Simulation started |
-------------------------------------

Battery: 100%

Mission successful!
Your parcel was delivered.
Trip completed successfully. 20% Battery is used.

Mission delayed due to rain.
The mission delayed due to rain.
Mission delayed.5% battery is used.

Mission failed due to obstacle.
The mission failed due to obstacle or rainy weather.
Mission failed. Battery used: 10% battery is used.


Successful Deliveries: 1
Failed Deliveries: 1
Delayed Deliveries: 1
Battery Left: 65
```

### Assumptions

- The simulation runs exactly 3 delivery missions
- Initial battery level is always 100%
- Weather conditions change randomly for each mission
- Obstacles appear randomly with equal probability
- Battery consumption rates are fixed for each outcome type

## Team Collaboration Summary

The project responsibilities were divided among team members to ensure efficient development. We handled the main logic design and implementation of the core functions collaboratively. The tester was responsible for running multiple test cases and identifying edge cases in battery management and decision logic.

We used Git for version control throughout the development process. We had the following branches while programming:
- Development 
- feature/environment
- feature/decision-logic
- systemControl


## AI Tool Reflection

We used AI during the development process to help with specific tasks. It was particularly useful for debugging syntax errors and understanding how to properly use the `rand()` function for random number generation. The AI also helped with structuring and formatting the Readme.md file.

What we learned from using AI tools is that they're really helpful for getting quick explanations of unfamiliar concepts.

## Future Improvements

If we had learned arrays or file handling, here are two improvements we could make:

- **Mission History Logging:** Using arrays, we could store all the mission details (weather, battery level, outcome) for each delivery attempt instead of just counting successes and failures. This would allow displaying a complete mission log at the end showing what happened in each attempt. With file handling, this data could be saved to a text file for future reference and analysis.

- **Multiple Drone Management:** With arrays, we could simulate multiple drones operating simultaneously, each with their own battery level and mission queue. This would make the simulation more realistic since actual delivery systems use fleets of drones rather than just one. File handling could be used to load initial drone configurations and save the final state of each drone.
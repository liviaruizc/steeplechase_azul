// steeplechase.cpp
// COP 2006 Summer 2024
// Livia Correia
// Program to make Azul travel through his world from the far left
// to the far right by jumping up the steeples across the board
// ------------------------------------------------------------
#include <Azul.h>

// GLOBAL CONSTANTS & Types
// ------------------------------------------------------------

enum AzulState { // defining all different states of Azul
    Stopping,
    MovingDown,
    Checking,
    Stepping,
    MovingUp
};

// Function declarations
// ------------------------------------------------------------

AzulState check (fgcu::Azul &azul);
AzulState stepForward (fgcu::Azul &azul);
AzulState down (fgcu::Azul &azul);
AzulState moveUp (fgcu::Azul &azul);
void turnRight (fgcu::Azul &azul);

// Function definitions
// ------------------------------------------------------------


int main()
{
    fgcu::Azul azul{fgcu::Azul::AzulExercise::Steeplechase};

    AzulState state{Stepping}; // Azul's initial state

    while (state != Stopping) { // main state loop

        switch (state) {
            case Stepping:
                state = stepForward(azul);
                break;

            case MovingDown:
                state = down(azul);
                break;

            case MovingUp:
                state = moveUp(azul);
                break;

            case Checking:
                state = check(azul);

        } // switch statement
    } // end main loop


    azul.stop(); // have azul stop here to keep the window open
} // end main

/**
 * Check for steeples and changing the state either
 * if there is a steeple or if there is not
 * @param azul - mascot
 * @return will return either a Stepping state or a MovingUp state
 */
AzulState check (fgcu::Azul &azul) {
    AzulState newState{Checking};
    if (azul.canMoveForward()) {
        newState = Stepping;
    }
    else {
        newState = MovingUp;
    }

    return newState;
} // end of check


/**
 * If there is steeple, move Azul up until he has space to move foward again
 * @param azul - mascot
 * @return - return moving down when Azul has space to give a step or check again for steeples
 */
AzulState moveUp (fgcu::Azul &azul) {
    AzulState newState{MovingUp};
    azul.turnLeft();
    azul.moveForward();
    turnRight(azul);
    if (azul.canMoveForward()) {
        azul.moveForward();
        newState = MovingDown;
    }
    else {
        newState = Checking;
    }

    return newState;
} // end of MoveUp


/**
 * If there is no need to move up, continue Azul's movement until he finds
 * the first steeple
 * @param azul - mascot
 * @return - When finding first steeple will go back to checking
 */
AzulState stepForward (fgcu::Azul &azul) {
    AzulState newState{Stepping};
    while (azul.canMoveForward()) {
        azul.moveForward();
    }
    newState = Checking;

    return newState;
} // end StepFoward


/**
 * Move Azul down until he reaches the border of the board, turning him East when it does.
 * @param azul
 * @return - return either checking stage when reaching bottom of board
 * or creating the condition to end loop by returning Stopping
 */
AzulState down (fgcu::Azul &azul) {
    AzulState newState{MovingDown};
    turnRight(azul);
    while (azul.canMoveForward()) {
        azul.moveForward();
    }
    azul.turnLeft();
    if (!azul.isBorderWall()) {
        newState = Checking;
    }
    else {
        newState = Stopping;
    }
    return newState;
} // end of down


/**
 * Turn Azul right by turning him left 3 times
 * @param azul - mascot
 */
void turnRight (fgcu::Azul &azul) {
    azul.turnLeft();
    azul.turnLeft();
    azul.turnLeft();
} // end of turnRight
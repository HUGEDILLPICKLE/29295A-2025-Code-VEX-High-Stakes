#ifndef TOGGLEBUTTON_HPP
#define TOGGLEBUTTON_HPP

#include "../include/pros/misc.hpp"
#include "../include/EZ-Template/util.hpp"

class ToggleButton
{

private:
    pros::Controller &Master_;
    bool Pressed_ = false;
    pros::controller_digital_e_t Button_;

public:
    ToggleButton(pros::controller_digital_e_t button, pros::Controller Master = master)
        : Master_(Master)
    {
        Button_ = button;
    }

    void Tick()
    {
        if (Master_.get_digital_new_press(Button_)){
            Pressed_ = !Pressed_;
        }
    }

    void setValue(bool value) {
        Pressed_ = value;
    }

    bool IsOn()
    {
        return Pressed_;
    }
}; 
#endif  // TOGGLEBUTTON_HPP
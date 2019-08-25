/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.beans;

import javax.ejb.Stateless;

/**
 *
 * @author Jatin
 */
@Stateless
public class ChocoBean {

    private String advice;

    public String getAdvice() {

        String msg;

        switch (advice) {
            case "chewy":
                msg = "You should try Five Star, Bar One.";
                break;
            case "crunchy":
                msg = "You should try Munch, KitKat.";
                break;
            default:
                msg = "Sorry, we can't help you.";
                break;
        }
        return msg;

    }

    public void setAdvice(String advice) {
        this.advice = advice;
    }
}

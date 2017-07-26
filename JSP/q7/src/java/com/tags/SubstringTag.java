/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.tags;

import java.io.IOException;
import javax.servlet.jsp.JspWriter;
import javax.servlet.jsp.JspException;
import javax.servlet.jsp.tagext.SimpleTagSupport;

/**
 *
 * @author Jatin
 */
public class SubstringTag extends SimpleTagSupport {

    private String input;
    private String start;
    private String end;

    public String getInput() {
        return input;
    }

    public void setInput(String input) {
        this.input = input;
    }

    public String getStart() {
        return start;
    }

    public void setStart(String start) {
        this.start = start;
    }

    public String getEnd() {
        return end;
    }

    public void setEnd(String end) {
        this.end = end;
    }

    private String getSubstring() {
        String substring;
        int len = input.length();
        int s = Integer.parseInt(start);
        int e = Integer.parseInt(end);

        if (s < 0 || e < 0 || s >= len || e >= len) {
            substring = "Invalid start or end indices";
        } else if (s > e) {
            substring = "Start index should be less than end index.";
        } else {
            substring = input.substring(s, e+1);
        }

        return substring;
    }

    /**
     * Called by the container to invoke this tag. The implementation of this
     * method is provided by the tag library developer, and handles all tag
     * processing, body iteration, etc.
     *
     * @throws javax.servlet.jsp.JspException
     * @throws java.io.IOException
     */
    @Override
    public void doTag() throws JspException, IOException {
        JspWriter out = getJspContext().getOut();
        
        out.println(getSubstring());

    }

}

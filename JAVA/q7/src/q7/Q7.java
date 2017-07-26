/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package q7;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

/**
 *
 * @author Jatin
 */
public class Q7 {

    /**
     * @param args the command line arguments 
     * args[0] is source file name, and args[1] is destination file name
     */
    public static void main(String[] args) throws IOException {
        System.out.println("********* File Copy System *********");
        System.out.println("The source and destination files have already been specified in command line arguments.");
        System.out.println(" To Change: go to Project->Properties->Run->Arguments->( space separated file names )\n");
        File sourceFile = new File(args[0]);
        FileInputStream fin = null;
        try {
            fin = new FileInputStream(sourceFile);
        } catch (FileNotFoundException ex) {
            System.out.println(ex.getMessage());
            System.exit(1);
        }

        File destinationFile = new File(args[1]);
        FileOutputStream fout = null;
        if (!destinationFile.exists()) {
            System.out.println("Destination File does not Exist. Creating New File... ");
            destinationFile.createNewFile();
        }
        try {
            fout = new FileOutputStream(destinationFile);
        } catch (FileNotFoundException ex) {
            System.out.println(ex.getMessage());
            System.exit(1);
        }

        System.out.println("Initializing File copying..... ");
        System.out.println("Total bytes to be copied : " + fin.available());

        int content;    // accessing 4 bytes at a time.
        try {
            while ((content = fin.read()) != -1) {
                fout.write(content);
            }
            System.out.println("File Copying Complete..... ");
        } catch (IOException err) {
            err.getMessage();
        } finally {
                fin.close();
                fout.close();
            }

    }

}

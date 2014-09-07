package com.biocis.utils;

import java.io.*;
import java.text.*;
import java.util.*;

public class SuperClusterSystem implements Runnable{

    String filename ;
    Vector chromosomes ;
    String session ;
    String cache ;
    SuperCluster enhancer ;
    String organism ;
    String OrgName ;

    public SuperClusterSystem (String  filename, Vector chromosomes, String session, String cache, String organism, String Name)
    {
		this.filename = filename ;
		this.chromosomes = chromosomes ;
		this.session = session ;
		this.cache = cache ;
		this.organism = organism ;
		this.OrgName = Name ;
    }

    public void run ()
    {

       for (int i  = 0 ; i < chromosomes.size() ; i++)
	    {
		String ChName = (String) chromosomes.elementAt(i) ;
		CreateSetup (filename, session, ChName, organism) ;
		String Command = "java -classpath /usr/share/tomcat6-BioScope/webapps/ge/WEB-INF/classes SuperCluster " +  filename  + "/config.txt " + ChName + " " +  session +  " " + cache ;
		ExecuteCommand (Command, true) ;
	    }

    }

    public static void sleep(int milliSeconds)
    {
      try
	  {
	      Thread.sleep (milliSeconds);
	  }
      catch (Exception e)
	  {
	      ;
	  }
    }




    public void PreSetup (String ConfigDir, String Sesid, String CName, String ReplaceString)
    {
        String ResultsDir = ConfigDir + "/" + Sesid + "_" + CName  ;
        DeleteFile (ResultsDir + "/" + CName + ".done") ;
    }

    public void CreateSetup (String ConfigDir, String Sesid, String CName, String ReplaceString)
    {
        String ResultsDir = ConfigDir + "/" + Sesid + "_" + CName  ;
        File file = new File (ResultsDir) ;
        if (!file.exists() || !file.canRead())
            {
                file.mkdirs() ;
            }
	String OrgDir = OrgName ;
	CopyBinaryFiles ("/usr/local/apache/htdocs/l.gif", ResultsDir + "/" + "l.gif") ;
	CopyBinaryFiles ("/usr/local/apache/htdocs/b.gif", ResultsDir + "/" + "b.gif") ;
	CopyBinaryFiles ("/usr/local/apache/htdocs/e.gif", ResultsDir + "/" + "e.gif") ;
	CopyBinaryFiles ("/usr/local/apache/htdocs/f.gif", ResultsDir + "/" + "f.gif") ;
	CopyBinaryFiles ("/usr/local/apache/htdocs/m.gif", ResultsDir + "/" + "m.gif") ;
	CopyBinaryFiles ("/usr/local/apache/htdocs/p.gif", ResultsDir + "/" + "p.gif") ;
	CopyBinaryFiles ("/usr/local/apache/htdocs/p.gif", ResultsDir + "/" + "p.gif") ;
	CopyBinaryFiles ("/usr/local/apache/htdocs/i.gif", ResultsDir + "/" + "i.gif") ;
	CopyBinaryFiles ("/usr/local/apache/htdocs/forward.gif", ResultsDir + "/" + "forward.gif") ;
	CopyBinaryFiles ("/usr/local/apache/htdocs/1.gif", ResultsDir + "/" + "1.gif") ;
	CopyBinaryFiles ("/usr/local/apache/htdocs/2.gif", ResultsDir + "/" + "2.gif") ;
	CopyBinaryFiles ("/usr/local/apache/htdocs/clear.gif", ResultsDir + "/" + "clear.gif") ;
	CopyBinaryFiles ("/usr/local/apache/htdocs/reverse.gif", ResultsDir + "/" + "reverse.gif") ;

        DeleteFile (ResultsDir + "/" + CName + ".done") ;
        DeleteFile (ResultsDir + "/" + CName + ".fa" ) ;
	ExecuteCommand ("ln -s  /usr/local/apache/htdocs/gbrowse/databases/" + OrgDir.toUpperCase() + "/" + CName + "/" + CName + ".fa " + ResultsDir + "/" , true) ;
        DeleteFile (ResultsDir + "/" + CName + ".gene" ) ;
        DeleteFile (ResultsDir + "/" + CName + ".gff" ) ;
        appendFiles ("/usr/local/apache/htdocs/gbrowse/databases/" + OrgDir.toUpperCase() + "/" + CName + "/" + CName + ".gff", ResultsDir + "/" + CName + ".gff" ) ;
        ExecuteCommand ("/usr/local/apache/cgi-bin/replacestring.pl -f /usr/local/apache/conf/gbrowse.conf/generic.conf  -s =organism -r =" + ReplaceString + " -o /usr/local/apache/conf/gbrowse.conf/" + Sesid + "_temp.conf" , true) ;
        ExecuteCommand ("/usr/local/apache/cgi-bin/replacestring.pl -f /usr/local/apache/conf/gbrowse.conf/" + Sesid + "_temp.conf" + "  -s /usr/local/apache/htdocs/gbrowse/databases  -r /usr/local/apache/htdocs/gbrowse/databases" + "/" + Sesid + "/" + Sesid + "_" + CName  +  " -o /usr/local/apache/conf/gbrowse.conf/" + Sesid + "_" + CName + ".conf" , true) ;
        DeleteFile ("/usr/local/apache/conf/gbrowse.conf/" + Sesid + "_temp.conf" ) ;
        appendFiles ("/usr/local/apache/conf/gbrowse.conf/Enhancer.conf", "/usr/local/apache/conf/gbrowse.conf/" + Sesid + "_" + CName + ".conf") ;

    }

    public void CopyBinaryFiles (String FileToBeCopied, String FileToCopy)
    {
	try
	{
	    File inputFile = new File(FileToBeCopied);
	    File outputFile = new File(FileToCopy);

	    FileInputStream in = new FileInputStream(inputFile);
	    FileOutputStream out = new FileOutputStream(outputFile);
	    int c;

	    while ((c = in.read()) != -1)
		out.write(c);

	    in.close();
	    out.close();
	}
	catch (IOException e)
	    {
		System.out.println ("SuperClusterSystem.java : Cannot copy file ") ;
	    }
    }

    public void appendFiles (String FileContent, String FileToAppend) {


        try {
            RandomAccessFile raf = new RandomAccessFile(FileToAppend, "rw");
            // Position yourself at the end of the f
            //     ile
	    raf.seek(raf.length());
            // Write the String into the file. Note
            //     that you must
            // explicitly handle line breaks.
            try
                {
                    FileReader fr = new FileReader (FileContent) ;
                    BufferedReader in = new BufferedReader (fr) ;
                    String line ;
                    try
                        {
			    while ((line = in.readLine()) != null)
                                {
                                    raf.writeBytes(line + "\n") ;
                                }
                            fr.close() ;
                        }
		       catch (IOException e)
                        {
                            System.out.println ("SuperClusterServlet.java : IO error occurred " + FileContent + "<p>") ;
                        }

                }
	    catch (FileNotFoundException e)
                {
                    System.out.println ("SuperClusterServlet.java : File not found " + FileContent + "<p>") ;
                }
	    raf.close() ;
        }
	catch (IOException e) {
            System.out.println("Error opening file: " + e);
        }

    }

    public void ExecuteCommand (String Command, boolean Wait)
    {
	try
	    {
		System.out.println(Command ) ;
                Process p ;
                p = Runtime.getRuntime().exec(Command);
		if (Wait)
		    {
			try
			    {
				int exitval = p.waitFor() ;
				System.out.println ("exit value " + exitval + "<br>") ;
			    }
			catch (InterruptedException e)
			    {
				System.out.println ("SuperClusterServlet.java : while executing " + Command + "  <br>") ;
			    }
		    }
	    }
	catch (IOException e)
	    {
		System.out.println ("SuperClusterServlet.java : Command " + Command + "Failed  <br>") ;
	    }

    }

    public void DeleteFile (String Filename)
    {
	File RemoveFile = new File (Filename) ;
	RemoveFile.delete() ;
    }

}



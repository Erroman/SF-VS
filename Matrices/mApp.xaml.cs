using System;
using static System.Console;
using System.Windows;
using System.Windows.Media;

partial class mApp:Application
{
	 mApp()
	{
		Matrix m = new Matrix();
		Point p1 = new Point(100,100);
		
		WriteLine("Matrices!");
		WriteLine("x = {0}, y = {1}",p1.X,p1.Y);
		m.M11 =3;
		m.M22 =2;
		m.OffsetX = 10;
		m.OffsetY = 20;
		WriteLine("{0}   {1}    0\n{2}   {3}    0\n{4}   {5}    1\n", m.M11,m.M12,m.M21,m.M22,m.OffsetX,m.OffsetY);
		Point p2 = m.Transform(p1);
		WriteLine("x = {0}, y = {1}",p2.X,p2.Y);
		//this.Shutdown();
		
	}	
}
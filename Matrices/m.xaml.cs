using System;
using System.Windows;
using System.Windows.Media;
using System.Windows.Controls;
using System.Windows.Shapes;
partial class M 
{
	Matrix m = new Matrix();
	Point p = new Point(100,100);
	Ellipse el;
	SolidColorBrush mySolidColorBrush = new SolidColorBrush();
	
	public M()
	{
		
	

	}
	void move_Ellipse(object o, RoutedEventArgs e)
	{
		/*this.myCanvas.Children.Remove(myEllipse);
		Canvas.SetTop(myEllipse,Canvas.GetTop(myEllipse)+10);
		Canvas.SetLeft(myEllipse,Canvas.GetLeft(myEllipse)+10);
		this.myCanvas.Children.Add(myEllipse);*/

		m.OffsetX = 10;
		m.OffsetY = 20;

		p=m.Transform(p);
		el = new Ellipse();
		//el.Fill=mySolidColorBrush;
		mySolidColorBrush.Color = Color.FromArgb(255, 255, 255, 0);
		el.StrokeThickness = 2;
        el.Stroke = Brushes.Red;

         // Set the width and height of the Ellipse.
         el.Width = 2;
         el.Height = 2;
		this.myCanvas.Children.Add(el);
		Canvas.SetTop(el,p.X);
		Canvas.SetLeft(el,p.Y);

	}
	void move_back_Ellipse(object o, RoutedEventArgs e)
	{
		m.OffsetX = -10;
		m.OffsetY = -20;

		p=m.Transform(p);
		Canvas.SetTop(myEllipse,p.X);
		Canvas.SetLeft(myEllipse,p.Y);
	}
	void move_in_cirle(object o, RoutedEventArgs e)
	{
		int originX = 450;
		int originY = 200;
		m.OffsetX = 0;
		m.OffsetY = 0;
		m.M11 = Math.Cos(0.01);
		m.M12 = Math.Sin(0.01);
		m.M21 = - Math.Sin(0.01);
		m.M22 = Math.Cos(0.01);
		
		
		for(int i=1;i<=10;i++)
		{
		p=m.Transform(p);
		el = new Ellipse();
		//el.Fill=mySolidColorBrush;
		mySolidColorBrush.Color = Color.FromArgb(255, 255, 255, 0);
		el.StrokeThickness = 2;
        el.Stroke = Brushes.Red;

         // Set the width and height of the Ellipse.
         el.Width = 2;
         el.Height = 2;
		this.myCanvas.Children.Add(el);
		Canvas.SetLeft(el,p.X+originX);
		Canvas.SetTop(el,p.Y+originY);
		}
	}
	
}
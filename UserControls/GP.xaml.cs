using System;
using static System.Console;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

partial class GraphPlotter
{
	private PointCollection points=null;
	private void GraphPlotter_Loaded(object o, RoutedEventArgs e)
	{
		if(points==null)
		{
		Rect rectBounds = VisualTreeHelper.GetDescendantBounds(canGraph);
		WriteLine("rectBounds.X = {0},rectBounds.Y = {1},rectBounds.Width = {2},rectBounds.Height = {3}",
		rectBounds.X,rectBounds.Y,rectBounds.Width,rectBounds.Height);
		const double margin = 10;
            double xmin = margin;
            double xmax = rectBounds.Width - margin;
            double ymin = margin;
            double ymax = rectBounds.Height - margin;
            const double step = 10;

            // Make the X axis.
            GeometryGroup xaxis_geom = new GeometryGroup();
            xaxis_geom.Children.Add(new LineGeometry(new Point(margin, ymax), new Point(rectBounds.Width, ymax)));
            for (double x = xmin + step; x <= rectBounds.Width - step; x += step)
            {
                xaxis_geom.Children.Add(new LineGeometry
				(
                    new Point(x, ymax - margin / 2),
                    new Point(x, ymax))
				);
            }

            Path xaxis_path = new Path();
            xaxis_path.StrokeThickness = 1;
            xaxis_path.Stroke = Brushes.Black;
            xaxis_path.Data = xaxis_geom;
            
            canGraph.Children.Add(xaxis_path);

            // Make the Y ayis.
            GeometryGroup yaxis_geom = new GeometryGroup();
            yaxis_geom.Children.Add(new LineGeometry(
                new Point(xmin, 0), new Point(xmin, rectBounds.Height-margin)));
            for (double y = step; y <= rectBounds.Height - step; y += step)
            {
                yaxis_geom.Children.Add(new LineGeometry(
                    new Point(xmin, y),
                    new Point(xmin + margin / 2, y)));
            }

            Path yaxis_path = new Path();
            yaxis_path.StrokeThickness = 1;
            yaxis_path.Stroke = Brushes.Black;
            yaxis_path.Data = yaxis_geom;

            canGraph.Children.Add(yaxis_path);

			double d = Math.Sin(1.0);
			points = new PointCollection();
//		    for (double x = xmin; x <= xmax; x += (step/1000)){points.Add(new Point(x,200+80*Math.Sin(x/80)));}
			for (double x = xmin; x <= xmax; x += (step/1000)){points.Add(new Point(x,ymax+margin-x));}
                Polyline polyline = new Polyline();
                polyline.StrokeThickness = 1;
                polyline.Stroke = Brushes.Red;
                polyline.Points = points;
                canGraph.Children.Add(polyline); 
        }
	}
}
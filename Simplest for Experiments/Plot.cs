using System;
using static System.Console;
using System.Windows;

using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Shapes;

using static TransformWorldToScreen;
class Plot
{
	public M main_window;
	public Canvas canvas_to_draw_upon;
	GeometryGroup axisX;
	double LowerLimitForTimeOnXAxis;
	double UpperLimitForTimeOnXAxis;
	double LowerLimitForCurrentOnYAxis;
	double UpperLimitForCurrentOnYAxis;	
	public void draw_plot(double LowerLimitForTimeOnXAxis,double UpperLimitForTimeOnXAxis)
	{
		const double marginX = 15;
		const double marginY = 30;
		const double dashHourTickLength = 10;
		const double dashHalfHourTickLength = 7;
		const double dashMinuteTickLength = 5;
		const double axisLineThickness = 1;

		double xmin = marginX;                                  //limits of device coordinates
		double xmax = canvas_to_draw_upon.ActualWidth-marginX;	
		double ymin = marginY;
		double ymax = canvas_to_draw_upon.ActualHeight-marginY;
		this.LowerLimitForTimeOnXAxis = LowerLimitForTimeOnXAxis;
		this.UpperLimitForTimeOnXAxis = UpperLimitForTimeOnXAxis;
		this.LowerLimitForCurrentOnYAxis = Int32.Parse(main_window.BottomLimit.Text);
		this.UpperLimitForCurrentOnYAxis = Int32.Parse(main_window.TopLimit.Text);
		
	

		PrepareTransformations
		(
			LowerLimitForTimeOnXAxis,UpperLimitForTimeOnXAxis,
			LowerLimitForCurrentOnYAxis,UpperLimitForCurrentOnYAxis,
			xmin,xmax,
			ymin,ymax
		);

		//Make the X axis.
		axisX = new GeometryGroup();
		axisX.Children.Add(new LineGeometry(WtoD(new Point(LowerLimitForTimeOnXAxis, LowerLimitForCurrentOnYAxis)), WtoD(new Point(UpperLimitForTimeOnXAxis, LowerLimitForCurrentOnYAxis))));
		//Расставляем часовые деления на оси X
		//Расставляем получасовые деления на оси X
		//Расставляем 10-минутные деления на оси X
		//Для крупного масштаба расставляем 5 - минутные
		//и минутные деления.
		Point onX_axis;
		Point overX_axis;
		Action<string,Point,HorizontalAlignment,VerticalAlignment> PutLabel = DrawText;;
		PutTimeTicks(3600,dashHourTickLength,PutLabel);
		PutLabel=null;
		PutTimeTicks(1800,dashHalfHourTickLength,PutLabel);
		PutTimeTicks(600,dashMinuteTickLength,PutLabel);
		if((UpperLimitForTimeOnXAxis-LowerLimitForTimeOnXAxis)/3600<=2)
		{
			PutTimeTicks(300,dashMinuteTickLength,PutLabel);
			PutTimeTicks(60,dashMinuteTickLength,PutLabel);
			
		}
		
		Path axisX_path = new Path();
        axisX_path.StrokeThickness = axisLineThickness;
        axisX_path.Stroke = Brushes.Black;
        axisX_path.Data = axisX;
		
		//Make the Y axis.
		GeometryGroup axisY = new GeometryGroup();
		axisY.Children.Add(new LineGeometry(WtoD(new Point(LowerLimitForTimeOnXAxis, LowerLimitForCurrentOnYAxis)), WtoD(new Point(LowerLimitForTimeOnXAxis, UpperLimitForCurrentOnYAxis))));
		
		Path axisY_path = new Path();
        axisY_path.StrokeThickness = axisLineThickness;
        axisY_path.Stroke = Brushes.Black;
        axisY_path.Data = axisY;
		
		canvas_to_draw_upon.Children.Add(axisX_path);
		canvas_to_draw_upon.Children.Add(axisY_path);
	}
	
	private void PutTimeTicks(int IntervalInSeconds,double TickLength,Action<string,Point,HorizontalAlignment,VerticalAlignment> PutLabel)
	{
		Point onX_axis;
		Point overX_axis;

		for(double Dash = TickMeasure(LowerLimitForTimeOnXAxis);Dash < UpperLimitForTimeOnXAxis;Dash+=IntervalInSeconds)
		{
				  onX_axis = WtoD(new Point(Dash,LowerLimitForCurrentOnYAxis));
				  overX_axis = onX_axis;
				  overX_axis.Y = overX_axis.Y - TickLength;
				  axisX.Children.Add(new LineGeometry
				(
					onX_axis,
					overX_axis
				)
				);
				Point underX_axis = onX_axis;
					  underX_axis.Y = overX_axis.Y;	
				if(PutLabel!=null)
				{
					PutLabel(((int)Dash / IntervalInSeconds).ToString(),underX_axis,HorizontalAlignment.Center,VerticalAlignment.Center);
				}
		
		}
		double TickMeasure(double timeInSeconds)
		{
			return (((int)timeInSeconds / IntervalInSeconds) + (( timeInSeconds % IntervalInSeconds == 0) ? 0:1))*IntervalInSeconds;
		}
	}

	private void DrawText(string text, Point location,
            HorizontalAlignment halign, VerticalAlignment valign)
        {
            // Make the label.
            Label label = new Label();
            label.Content = text;
            canvas_to_draw_upon.Children.Add(label);

            // Position the label.
            label.Measure(new Size(double.MaxValue, double.MaxValue));

            double x = location.X;
            if (halign == HorizontalAlignment.Center)
                x -= label.DesiredSize.Width / 2;
            else if (halign == HorizontalAlignment.Right)
                x -= label.DesiredSize.Width;
            Canvas.SetLeft(label, x);

            double y = location.Y;
            if (valign == VerticalAlignment.Center)
                y += label.DesiredSize.Height / 2;
            else if (valign == VerticalAlignment.Bottom)
                y += label.DesiredSize.Height;
            Canvas.SetTop(label, y);
        }

}
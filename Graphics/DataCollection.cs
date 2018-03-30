using System;
using System.Collections.Generic;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Shapes;
namespace LineCharts
{
public class DataCollection
{
private List<DataSeries> dataList;
public DataCollection()
{
dataList = new List<DataSeries>();
}

//Публичное свойство, через которое добавляются графики для отрисовки,
//с этого начинается работа с DataCollection
public List<DataSeries> DataList
{
get { return dataList; }
set { dataList = value; }
}
//А вызовом метода AddLines работа заканчивается,
//
public void AddLines(ChartStyle cs)
{
int j = 0;
foreach (DataSeries ds in DataList)
{
if (ds.SeriesName == "Default Name")
{
ds.SeriesName = "DataSeries" + j.ToString();
}
//вызываем метод , чтобы окончательно установить цвет и форму линии для графика,
//записывая свойства графика  в свойства добавляемой полилинии LineSeries
ds.AddLinePattern();
//перезаписываем мировые координаты точек полилинии в местные координаты на холсте.
for (int i = 0; i < ds.LineSeries.Points.Count; i++)
{
ds.LineSeries.Points[i] =
cs.NormalizePoint(ds.LineSeries.Points[i]);
}
cs.ChartCanvas.Children.Add(ds.LineSeries);
j++;
}
}
}
}
using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Shapes;
namespace LineCharts
{
public partial class LineChartWithGridlines : Window
{
private ChartStyleGridlines cs = new ChartStyleGridlines();
private DataCollection dc;
private DataSeries ds;
public LineChartWithGridlines()
{
InitializeComponent();
}
private void AddChart()
{
//Сообщаем классу , представляющему холст с координатными осями, его размеры 
//и тип линий, размечающих холст.
cs.ChartCanvas = chartCanvas;
cs.TextCanvas = textCanvas;
cs.Title = "Sine and Cosine Chart";
cs.Xmin = 0;
cs.Xmax = 7;
cs.Ymin = -1.5;
cs.Ymax = 1.5;
cs.XTick = 0.5;
cs.YTick = 0.5;
//cs.IsYGrid = false;
cs.GridlinePattern = ChartStyleGridlines.GridlinePatternEnum.Dot;
cs.GridlineColor = Brushes.Black;
// Наносим на холст заголовок tbTitle для графиков и координатные оси с обозначениями tbXLabel и tbYLabel
cs.AddChartStyle(tbTitle,tbXLabel,tbYLabel);
//теперь в cs находится холст с размеченными и обозначенными координатными осями
//занимаемся подготовкой линий для графиков, для хранения линии предназначен объект ds
//создаём объект для линии графика
ds = new DataSeries();
// Draw Sine curve:
//Цвет и толщина линии для графика Sin
ds.LineColor = Brushes.Blue;
ds.LineThickness = 2;
//Добавляем точки в мировых координатах для графика Sin
for (int i = 0; i < 50; i++)
{
double x = i / 5.0;
double y = Math.Sin(x);
ds.LineSeries.Points.Add(new Point(x, y));
}
//Добавляем полученную линию графика к коллекции линий, предназначенных для отриоовки
//Создаём коллекцию линий
dc = new DataCollection();
//Добавляем Sin график к коллекции
dc.DataList.Add(ds);
// Draw cosine curve:
ds = new DataSeries();
//Цвет, толщина и тип линии для графика Cos
ds.LineColor = Brushes.Red;
ds.LinePattern = DataSeries.LinePatternEnum.DashDot;
ds.LineThickness = 2;
for (int i = 0; i < 50; i++)
{
double x = i / 5.0;
double y = Math.Cos(x);
ds.LineSeries.Points.Add(new Point(x, y));
}
//Добавляем Cos график к коллекции
dc.DataList.Add(ds);
//Отрисовываем графики,добавляя подготовленную коллецию на холст
//с заголовком и уже подготовленными осями координат с обозначаниеми на них 
dc.AddLines(cs);
}
private void chartGrid_SizeChanged(object sender, SizeChangedEventArgs e)
{
textCanvas.Width = chartGrid.ActualWidth;
textCanvas.Height = chartGrid.ActualHeight;
chartCanvas.Children.Clear();
textCanvas.Children.RemoveRange(1, textCanvas.Children.Count - 1);
//textCanvas.Children.RemoveRange(0, textCanvas.Children.Count);
AddChart();
}
}
}
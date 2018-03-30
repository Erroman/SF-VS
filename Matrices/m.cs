using System;
using static System.Console;
using System.Windows.Media;

class M	
{
	static Matrix m;
	static Matrix m1;
	static void Main()
	{
	
	WriteLine("{0}   {1}    0\n{2}   {3}    0\n{4}   {5}    1\n", m.M11,m.M12,m.M21,m.M22,m.OffsetX,m.OffsetY);
	
	m.Scale(2,3);
	WriteLine("{0}   {1}    0\n{2}   {3}    0\n{4}   {5}    1\n", m.M11,m.M12,m.M21,m.M22,m.OffsetX,m.OffsetY);
	m = m*m;
	WriteLine("{0}   {1}    0\n{2}   {3}    0\n{4}   {5}    1\n", m.M11,m.M12,m.M21,m.M22,m.OffsetX,m.OffsetY);
	m = m*m1;
	WriteLine("{0}   {1}    0\n{2}   {3}    0\n{4}   {5}    1\n", m.M11,m.M12,m.M21,m.M22,m.OffsetX,m.OffsetY);

	}
}
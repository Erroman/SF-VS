using System;
using static System.Console;
using System.Configuration;
using System.IO;
//using myApplicationSettingsBase;
class MyLocalFileSettingsProvider:LocalFileSettingsProvider
{
	
}
class SP
{
	static void Main()
	{
		Settings mySettings = new Settings();
//		mySettings.SettingsKey = @"C:\user.config";
//		Settings.Default.SettingsKey = @"C:\user.config";
		Settings.Default.SettingsKey = @".\app.exe.config";
		WriteLine("That is mySettings.Price {0}",mySettings.Price);
		mySettings.Price = 145641.66;
		mySettings.Price = 91919191.444;
        mySettings.Save();
		WriteLine(File.Exists(System.Configuration.ConfigurationManager.OpenExeConfiguration(System.Configuration.ConfigurationUserLevel.PerUserRoaming).FilePath));
	}
}
//[SettingsProvider(typeof(MyProvider))]
//[SettingsProvider(typeof(CustomSettingsProvider))]
[SettingsProvider(typeof(MyLocalFileSettingsProvider))]
class Settings:myApplicationSettingsBase.ApplicationSettingsBase
{
	
	private static Settings defaultInstance = ((Settings)(global::System.Configuration.ApplicationSettingsBase.Synchronized(new Settings())));
        
    public static Settings Default 
	{
		get 
		{
             return defaultInstance;
        }
    }
	[UserScopedSetting]
	[DefaultSettingValue("777.777")]
	public double Price
	{
		get{return (double)this["Price"];}
		set{this["Price"] = value;}
	}
}

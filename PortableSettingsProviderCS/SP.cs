using System;
using static System.Console;
using System.Configuration;
using System.IO;
class SP
{
	static void Main()
	{
		Settings mySettings = new Settings();
		WriteLine("That is mySettings.Price {0}",mySettings.Price);
		mySettings.Price = 33333.333;
        mySettings.Save();
	}
}
[SettingsProvider(typeof(LocalFileSettingsProvider))]
class Settings:ApplicationSettingsBase
{
	static string hiddenSettingsFilePath = System.Configuration.ConfigurationManager.OpenExeConfiguration(System.Configuration.ConfigurationUserLevel.PerUserRoamingAndLocal).FilePath;
	static string localSettingsFilePath =  AppDomain.CurrentDomain.BaseDirectory+"user.config";
	static Settings()
	{
		if(File.Exists(localSettingsFilePath))
		File.Copy(localSettingsFilePath,hiddenSettingsFilePath,true);
	}
	
	[UserScopedSetting]
	[DefaultSettingValue("777.777")]
	public double Price
	{
		get{return (double)this["Price"];}
		set{this["Price"] = value;}
	}
	public override void Save()
	{
		base.Save();
		File.Copy(hiddenSettingsFilePath,localSettingsFilePath,true);
	}
}

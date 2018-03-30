using System;
using static System.Console;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Configuration;
using System.Reflection;
using System.Xml.Linq;
using System.Xml;
using System.IO;

class MyProvider:SettingsProvider
{
	
        
	//public override string Name = {"Friendly name";}
    public override void Initialize(string name, System.Collections.Specialized.NameValueCollection config)
    {
        base.Initialize(ApplicationName, config);
		Console.WriteLine("ApplicationName {0}",ApplicationName);
		Console.WriteLine("config {0}",config);

		
    }

	public override SettingsPropertyValueCollection GetPropertyValues(SettingsContext context, SettingsPropertyCollection collection)
	{
		WriteLine("GetPropertyValues starts!");
		SettingsPropertyValueCollection values = new SettingsPropertyValueCollection();
		foreach (SettingsProperty setting in collection)
		{
			WriteLine("I am in foreach!");
			SettingsPropertyValue value = new SettingsPropertyValue(setting);
			value.IsDirty = false;
			value.SerializedValue = GetValue(setting);
			values.Add(value);
		}
		WriteLine("GetPropertyValues continues...values.Count = {0}",values.Count);		
		WriteLine("value = {0}",values["Price"].PropertyValue);		
		WriteLine("collection['Price'].PropertyValue = {0}",collection["Price"]);		

		return values;				
	}
	public override void SetPropertyValues(SettingsContext context, SettingsPropertyValueCollection collection)
	{
		
	}

	private string GetValue(SettingsProperty setting)
	{
		string ret = "";
		return ret;
		
	}
	private XmlDocument m_SettingsXML = null;
	XmlDocument SettingsXML
	{
		get
		{
			if(m_SettingsXML == null)
				m_SettingsXML = new XmlDocument();
			return new XmlDocument();
		}
	} 
	public override string ApplicationName
	{
		get
		{
			return Path.GetFileNameWithoutExtension(System.Reflection.Assembly.GetExecutingAssembly().ManifestModule.Name);
		}
		set
		{
			//do nothing
		}
	}
	protected virtual string GetAppSettingsPath()
	{
		    return AppDomain.CurrentDomain.BaseDirectory;
	}
	protected virtual string GetAppSettingsFilename()
	{
		 return ApplicationName + ".settings";
	}
	private bool IsRoaming(SettingsProperty prop)
	{
		// Determine if the setting is marked as Roaming
		foreach(DictionaryEntry d in prop.Attributes)
		{
			Attribute a = (Attribute)d.Value;
			if(a is SettingsManageabilityAttribute)
				return true;
		}
		return false;
	}
			
}
#include "AppSettings.h"

#define __STDC_FORMAT_MACROS
#include <stdint.h>
#include <inttypes.h>

AppSettings::AppSettings()
{
}

AppSettings::~AppSettings()
{
	delete settings;
}

void AppSettings::initWithBlackDocument(const char* projectName, const char* version)
{
	settings = new TiXmlDocument();

	TiXmlDeclaration* declaration = new TiXmlDeclaration( "1.0", "", "" );  
	settings->LinkEndChild(declaration);

	curElement = new TiXmlElement("SettingsRoot");
	curElement->SetAttribute("ProjectName",projectName);
	curElement->SetAttribute("Version", version);
	settings->LinkEndChild(curElement);

}

void AppSettings::initWithExistingDocument(const char* projectName, const char* version, const char* fileName)
{
	settings = new TiXmlDocument(fileName);
	settings->LoadFile();
	curElement = settings->FirstChildElement("SettingsRoot");
	if (!curElement) {
		settings->Clear();
		TiXmlDeclaration* declaration = new TiXmlDeclaration( "1.0", "", "" );  
		settings->LinkEndChild(declaration);

		curElement = new TiXmlElement("SettingsRoot");
		curElement->SetAttribute("ProjectName",projectName);
		curElement->SetAttribute("Version", version);
		settings->LinkEndChild(curElement);
	}
}

AppSettings* AppSettings::appSettingsWithBlackDocument(const char* projectName, const char* version)
{
	AppSettings *as = new AppSettings();
	as->initWithBlackDocument(projectName, version);

	if (as)
	{
		as->autorelease();
		return as;
	}
	CC_SAFE_DELETE(as);
	return NULL;
}

AppSettings* AppSettings::appSettingsWithExistingDocument(const char* projectName, const char* version, const char* fileName)
{
	AppSettings *as = new AppSettings();
	as->initWithExistingDocument(projectName, version, fileName);

	if (as)
	{
		as->autorelease();
		return as;
	}
	CC_SAFE_DELETE(as);
	return NULL;
}

bool AppSettings::saveDocumentToFile(const char* fileName)
{
	return settings->SaveFile(fileName);
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 

bool AppSettings::createElement( const char* elemName )
{
	if (findElement(elemName))
		return false;
	TiXmlElement *newElement = new TiXmlElement(elemName);
	curElement->LinkEndChild(newElement); 
	curElement = newElement;
	return true;
}


bool AppSettings::setAttribute( const char* name, const char* value )
{
	if (strstr(name," ") != NULL) {
		return false; //Name of the attribute should not contain whitespaces.
	}
	curElement->SetAttribute(name, value);
	return true;
}

bool AppSettings::findParent()
{
	if (curElement->Parent()==settings) {//Current element is root element. 
		goToRootElement();
		return false;
	} else {
		curElement = (TiXmlElement*) curElement->Parent(); //Due to our functionality, a parent of the element is always TiXmlElement.
		return true;
	}
}

void AppSettings::goToRootElement()
{
	curElement = settings->FirstChildElement("SettingsRoot");
}

bool AppSettings::findElement( const char* elemName )
{
	TiXmlElement* element = curElement->FirstChildElement(elemName);
	if (element) {
		curElement = element;
		return true;
	} 
	return false;
}

bool AppSettings::addSimpleInt( const char* elemName, int param )
{
	if (strstr(elemName," ") != NULL) {
		return false; //Name of the attribute should not contain whitespaces.
	}
	TiXmlElement* root = settings->FirstChildElement("SettingsRoot");
	TiXmlElement* newElement = root->FirstChildElement(elemName);
	if (!newElement) {
		newElement = new TiXmlElement(elemName);
		root->LinkEndChild(newElement);
	}
	newElement->SetAttribute("value", param);
	return true;
}

bool AppSettings::addSimpleFloat( const char* elemName, float param )
{
	if (strstr(elemName," ") != NULL) {
		return false; //Name of the attribute should not contain whitespaces.
	}
	TiXmlElement* root = settings->FirstChildElement("SettingsRoot");
	TiXmlElement* newElement = root->FirstChildElement(elemName);
	if (!newElement) {
		newElement = new TiXmlElement(elemName);
		root->LinkEndChild(newElement);
	}
	char buf[255];
	sprintf(buf, "%f", param);
	newElement->SetAttribute("value", buf);
	return true;
}

bool AppSettings::addSimpleString( const char* elemName, const char* param )
{
	if (strstr(elemName," ") != NULL) {
		return false; //Name of the attribute should not contain whitespaces.
	}
	TiXmlElement* root = settings->FirstChildElement("SettingsRoot");
	TiXmlElement* newElement = root->FirstChildElement(elemName);
	if (!newElement) {
		newElement = new TiXmlElement(elemName);
		root->LinkEndChild(newElement);
	}
	newElement->SetAttribute("value", param);
	return true;
}

bool AppSettings::addSimpleBool( const char* elemName, bool param )
{
	if (strstr(elemName," ") != NULL) {
		return false; //Name of the attribute should not contain whitespaces.
	}
	TiXmlElement* root = settings->FirstChildElement("SettingsRoot");
	TiXmlElement* newElement = root->FirstChildElement(elemName);
	if (!newElement) {
		newElement = new TiXmlElement(elemName);
		root->LinkEndChild(newElement);
	}
	newElement->SetAttribute("value", param?1:0);
	return true;
}

bool AppSettings::addIntArray( const char* elemName, int arrayLength, int* params )
{
	if (strstr(elemName," ") != NULL) {
		return false; //Name of the attribute should not contain whitespaces.
	}
	TiXmlElement* root = settings->FirstChildElement("SettingsRoot");
	TiXmlElement* newElement = root->FirstChildElement(elemName);
	if (!newElement) {
		newElement = new TiXmlElement(elemName);
		root->LinkEndChild(newElement);
	}
	newElement->Clear();
	newElement->SetAttribute("paramsCount",arrayLength);
	for (int i = 0; i<arrayLength; i++) {
		char paramName[255];
		sprintf(paramName,"arg%d",i);
		TiXmlElement *paramElement = new TiXmlElement(paramName);
		newElement->LinkEndChild(paramElement); 
		paramElement->SetAttribute("value", params[i]);
	}
	return true;
}

bool AppSettings::addFloatArray( const char* elemName, int arrayLength, float* params )
{
	if (strstr(elemName," ") != NULL) {
		return false; //Name of the attribute should not contain whitespaces.
	}
	TiXmlElement* root = settings->FirstChildElement("SettingsRoot");
	TiXmlElement* newElement = root->FirstChildElement(elemName);
	if (!newElement) {
		newElement = new TiXmlElement(elemName);
		root->LinkEndChild(newElement);
	}
	newElement->Clear();
	newElement->SetAttribute("paramsCount",arrayLength);
	for (int i = 0; i<arrayLength; i++) {
		char paramName[255];
		sprintf(paramName,"arg%d",i);
		char param[255];
		sprintf(param,"%f",params[i]);
		TiXmlElement *paramElement = new TiXmlElement(paramName);
		newElement->LinkEndChild(paramElement); 
		paramElement->SetAttribute("value", param);
	}
	return true;
}

bool AppSettings::addStringArray( const char* elemName, int arrayLength, char** params )
{
	if (strstr(elemName," ") != NULL) {
		return false; //Name of the attribute should not contain whitespaces.
	}
	TiXmlElement* root = settings->FirstChildElement("SettingsRoot");
	TiXmlElement* newElement = root->FirstChildElement(elemName);
	if (!newElement) {
		newElement = new TiXmlElement(elemName);
		root->LinkEndChild(newElement);
	}
	newElement->Clear();
	newElement->SetAttribute("paramsCount",arrayLength);
	for (int i = 0; i<arrayLength; i++) {
		char paramName[255];
		sprintf(paramName,"arg%d",i);
		TiXmlElement *paramElement = new TiXmlElement(paramName);
		newElement->LinkEndChild(paramElement); 
		paramElement->SetAttribute("value", params[i]);
	}
	return true;
}

bool AppSettings::addBoolArray( const char* elemName, int arrayLength, bool* params )
{
	if (strstr(elemName," ") != NULL) {
		return false; //Name of the attribute should not contain whitespaces.
	}
	TiXmlElement* root = settings->FirstChildElement("SettingsRoot");
	TiXmlElement* newElement = root->FirstChildElement(elemName);
	if (!newElement) {
		newElement = new TiXmlElement(elemName);
		root->LinkEndChild(newElement);
	}
	newElement->Clear();
	newElement->SetAttribute("paramsCount",arrayLength);
	for (int i = 0; i<arrayLength; i++) {
		char paramName[255];
		sprintf(paramName,"arg%d",i);
		TiXmlElement *paramElement = new TiXmlElement(paramName);
		newElement->LinkEndChild(paramElement); 
		paramElement->SetAttribute("value", (params[i])?1:0);
	}
	return true;
}

bool AppSettings::loadSimpleInt( const char* elemName, int& param )
{
	if (strstr(elemName," ") != NULL) {
		return false; //Name of the attribute should not contain whitespaces.
	}
	TiXmlElement* root = settings->FirstChildElement("SettingsRoot");
	TiXmlElement* foundElement = root->FirstChildElement(elemName);
	if (!foundElement) {
		return false; //Document must contain information about param.
	}
	const char* paramBuf = foundElement->Attribute("value");
	if (!paramBuf) {
		return false; //Element must contain attribute with name 'value'
	}
	int newParam;
	if (!sscanf(paramBuf,"%d",&newParam)) {
		return false; //Wrong value format.
	}
	param = newParam;
	return true;
}

bool AppSettings::loadSimpleFloat( const char* elemName, float& param )
{
	if (strstr(elemName," ") != NULL) {
		return false; //Name of the attribute should not contain whitespaces.
	}
	TiXmlElement* root = settings->FirstChildElement("SettingsRoot");
	TiXmlElement* foundElement = root->FirstChildElement(elemName);
	if (!foundElement) {
		return false; //Document must contain information about param.
	}
	const char* paramBuf = foundElement->Attribute("value");
	if (!paramBuf) {
		return false; //Element must contain attribute with name 'value'
	}
	float newParam;
	if (!sscanf(paramBuf,"%f",&newParam)) {
		return false; //Wrong value format.
	}
	param = newParam;
	return true;
}

bool AppSettings::loadSimpleBool( const char* elemName, bool& param )
{
	if (strstr(elemName," ") != NULL) {
		return false; //Name of the attribute should not contain whitespaces.
	}
	TiXmlElement* root = settings->FirstChildElement("SettingsRoot");
	TiXmlElement* foundElement = root->FirstChildElement(elemName);
	if (!foundElement) {
		return false; //Document must contain information about param.
	}
	const char* paramBuf = foundElement->Attribute("value");
	if (!paramBuf) {
		return false; //Element must contain attribute with name 'value'
	}
	int newParam;
	if (!sscanf(paramBuf,"%d",&newParam)) {
		return false; //Wrong value format.
	}
	param = newParam;
	return true;
}

bool AppSettings::loadSimpleString( const char* elemName, char* param )
{
	if (strstr(elemName," ") != NULL) {
		return false; //Name of the attribute should not contain whitespaces.
	}
	TiXmlElement* root = settings->FirstChildElement("SettingsRoot");
	TiXmlElement* foundElement = root->FirstChildElement(elemName);
	if (!foundElement) {
		return false; //Document must contain information about param.
	}
	const char* paramBuf = foundElement->Attribute("value");
	if (!paramBuf) {
		return false; //Element must contain attribute with name 'value'
	}
	strcpy(param,paramBuf);
	return true;
}

bool AppSettings::loadIntArray( const char* elemName, int& arrayLength, int* params )
{
	if (strstr(elemName," ") != NULL) {
		return false; //Name of the attribute should not contain whitespaces.
	}
	TiXmlElement* root = settings->FirstChildElement("SettingsRoot");
	TiXmlElement* foundElement = root->FirstChildElement(elemName);
	if (!foundElement) {
		return false; //Document must contain information about param.
	}
	const char* countBuf = foundElement->Attribute("paramsCount");
	if (!countBuf) {
		return false; //Element must contain attribute with name 'paramsCount'
	}
	int newCount;
	if (!sscanf(countBuf,"%d",&newCount)) {
		return false; //Wrong value format.
	}
	arrayLength = min(arrayLength,newCount);
	for (int i = 0; i<arrayLength; i++) {
		char paramName[255];
		sprintf(paramName,"arg%d",i);
		TiXmlElement *paramElement = foundElement->FirstChildElement(paramName);
		const char* paramBuf = paramElement->Attribute("value");
		if (!paramBuf) {
			return false; //Element must contain attribute with name 'value'
		}
		int newParam;
		if (!sscanf(paramBuf,"%d",&newParam)) {
			return false; //Wrong value format.
		}
		params[i] = newParam;
	}
	return true;
}

bool AppSettings::loadBoolArray( const char* elemName, int& arrayLength, bool* params )
{
	if (strstr(elemName," ") != NULL) {
		return false; //Name of the attribute should not contain whitespaces.
	}
	TiXmlElement* root = settings->FirstChildElement("SettingsRoot");
	TiXmlElement* foundElement = root->FirstChildElement(elemName);
	if (!foundElement) {
		return false; //Document must contain information about param.
	}
	const char* countBuf = foundElement->Attribute("paramsCount");
	if (!countBuf) {
		return false; //Element must contain attribute with name 'paramsCount'
	}
	int newCount;
	if (!sscanf(countBuf,"%d",&newCount)) {
		return false; //Wrong value format.
	}
	arrayLength = min(arrayLength,newCount);
	for (int i = 0; i<arrayLength; i++) {
		char paramName[255];
		sprintf(paramName,"arg%d",i);
		TiXmlElement *paramElement = foundElement->FirstChildElement(paramName);
		const char* paramBuf = paramElement->Attribute("value");
		if (!paramBuf) {
			return false; //Element must contain attribute with name 'value'
		}
		int newParam;
		if (!sscanf(paramBuf,"%d",&newParam)) {
			return false; //Wrong value format.
		}
		params[i] = newParam;
	}
	return true;
}

bool AppSettings::loadFloatArray( const char* elemName, int& arrayLength, float* params )
{
	if (strstr(elemName," ") != NULL) {
		return false; //Name of the attribute should not contain whitespaces.
	}
	TiXmlElement* root = settings->FirstChildElement("SettingsRoot");
	TiXmlElement* foundElement = root->FirstChildElement(elemName);
	if (!foundElement) {
		return false; //Document must contain information about param.
	}
	const char* countBuf = foundElement->Attribute("paramsCount");
	if (!countBuf) {
		return false; //Element must contain attribute with name 'paramsCount'
	}
	int newCount;
	if (!sscanf(countBuf,"%d",&newCount)) {
		return false; //Wrong value format.
	}
	arrayLength = min(arrayLength,newCount);
	for (int i = 0; i<arrayLength; i++) {
		char paramName[255];
		sprintf(paramName,"arg%d",i);
		TiXmlElement *paramElement = foundElement->FirstChildElement(paramName);
		const char* paramBuf = paramElement->Attribute("value");
		if (!paramBuf) {
			return false; //Element must contain attribute with name 'value'
		}
		float newParam;
		if (!sscanf(paramBuf,"%f",&newParam)) {
			return false; //Wrong value format.
		}
		params[i] = newParam;
	}
	return true;
}

bool AppSettings::loadStringArray( const char* elemName, int& arrayLength, char** params )
{

	if (strstr(elemName," ") != NULL) {
		return false; //Name of the attribute should not contain whitespaces.
	}
	TiXmlElement* root = settings->FirstChildElement("SettingsRoot");
	TiXmlElement* foundElement = root->FirstChildElement(elemName);
	if (!foundElement) {
		return false; //Document must contain information about param.
	}
	const char* countBuf = foundElement->Attribute("paramsCount");
	if (!countBuf) {
		return false; //Element must contain attribute with name 'paramsCount'
	}
	int newCount;
	if (!sscanf(countBuf,"%d",&newCount)) {
		return false; //Wrong value format.
	}
	arrayLength = min(arrayLength,newCount);
	for (int i = 0; i<arrayLength; i++) {
		char paramName[255];
		sprintf(paramName,"arg%d",i);
		TiXmlElement *paramElement = foundElement->FirstChildElement(paramName);
		const char* paramBuf = paramElement->Attribute("value");
		if (!paramBuf) {
			return false; //Element must contain attribute with name 'value'
		}
		strcpy(params[i], paramBuf);
	}
	return true;
}

const char* AppSettings::getVersion()
{
	TiXmlElement* root = settings->FirstChildElement("SettingsRoot");
	return root->Attribute("Version");
}

const char* AppSettings::getAppName()
{
	TiXmlElement* root = settings->FirstChildElement("SettingsRoot");
	return root->Attribute("ProjectName");
}

bool AppSettings::addSimpleLongLong( const char* elemName, long long param )
{
	if (strstr(elemName," ") != NULL) {
		return false; //Name of the attribute should not contain whitespaces.
	}
	TiXmlElement* root = settings->FirstChildElement("SettingsRoot");
	TiXmlElement* newElement = root->FirstChildElement(elemName);
	if (!newElement) {
		newElement = new TiXmlElement(elemName);
		root->LinkEndChild(newElement);
	}
	char buf[255];
	sprintf(buf, "%lld", param);
	newElement->SetAttribute("value", buf);
	return true;
}

bool AppSettings::loadSimpleLongLong( const char* elemName, long long& param )
{

	if (strstr(elemName," ") != NULL) {
		return false; //Name of the attribute should not contain whitespaces.
	}
	TiXmlElement* root = settings->FirstChildElement("SettingsRoot");
	TiXmlElement* foundElement = root->FirstChildElement(elemName);
	if (!foundElement) {
		return false; //Document must contain information about param.
	}
	const char* paramBuf = foundElement->Attribute("value");
	if (!paramBuf) {
		return false; //Element must contain attribute with name 'value'
	}
	long long newParam;
	if (!sscanf(paramBuf,"%lld",&newParam)) {
		return false; //Wrong value format.
	}
	param = newParam;
	return true;
}

bool AppSettings::isEmpty()
{
	return !(curElement->FirstChildElement());
}

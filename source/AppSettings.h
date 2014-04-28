#ifndef __APPSETTINGS_H__
#define __APPSETTINGS_H__

#include "cocos2d.h"
#include "tinyxml.h"

USING_NS_CC;

class AppSettings : public CCObject
{
private:
	TiXmlDocument* settings;
	TiXmlElement* curElement;
private:
	AppSettings();
	~AppSettings();
	void initWithBlackDocument(const char* projectName, const char* version);
	void initWithExistingDocument(const char* projectName, const char* version, const char* fileName);

	void goToRootElement();

public:
/* Creates a new XML document. */
	static AppSettings* appSettingsWithBlackDocument(const char* projectName, const char* version);
/* Opens an existing document. If the document is empty, creates declaration and root element. */
	static AppSettings* appSettingsWithExistingDocument(const char* projectName, const char* version, const char* fileName);

/*	Saves document to the file. 
	Returns 'true', if no error occurred, 'false' - otherwise. */
	bool saveDocumentToFile(const char* fileName);

	const char* getVersion();
	const char* getAppName();

/*	Creates a new element, links it to the current one and navigates to it. 
	Returns 'true', if element has been created, 'false' - if it already exists. */	
	bool createElement(const char* elemName);
/*	Navigates to the element with the given name.
	Returns 'true', if element has been found, 'false' - otherwise.*/	
	bool findElement(const char* elemName);
/*	Set attribute of the current element.
	Returns 'true', if attribute has been set, 'false' - otherwise.*/
	bool setAttribute(const char* name, const char* value);
/*	Navigates to the parent of the current element.
	Returns 'true', if element has been found, 'false' - if current element is root element.*/
	bool findParent();

/*	Saves simple settings. Note that elements will be added to root element.
	All functions from this group return 'true', if param has been set, 'false' - otherwise. */

/*	Saves simple integer.*/
	bool addSimpleInt(const char* elemName, int param);
/*	Saves simple long int.*/
	bool addSimpleLongLong(const char* elemName, long long param);
/*	Saves simple float.*/
	bool addSimpleFloat(const char* elemName, float param);
/*	Saves simple string.*/
	bool addSimpleString(const char* elemName, const char* param);
/*	Saves simple boolean.*/
	bool addSimpleBool(const char* elemName, bool param);
/*	Saves integer array.*/
	bool addIntArray(const char* elemName, int arrayLength, int* params);
/*	Saves float array.*/
	bool addFloatArray(const char* elemName, int arrayLength, float* params);
/*	Saves string array.*/
	bool addStringArray(const char* elemName, int arrayLength, char** params);
/*	Saves boolean array.*/
	bool addBoolArray(const char* elemName, int arrayLength, bool* params);

/*	Loads simple settings. Note that elements will be searched in the root element.
	All function from this group return 'true', if param has been set, 'false' - otherwise. */

/*	Loads simple integer. */
	bool loadSimpleInt(const char* elemName, int& param);
/*	Loads simple long int. */
	bool loadSimpleLongLong(const char* elemName, long long& param);
/*	Loads simple float. */
	bool loadSimpleFloat(const char* elemName, float& param);
/*	Loads simple boolean. */
	bool loadSimpleBool(const char* elemName, bool& param);
/*	Loads simple string. */
	bool loadSimpleString(const char* elemName, char* param);
/*	Loads integer array. */
	bool loadIntArray(const char* elemName, int& arrayLength, int* params);
/*	Loads boolean array. */
	bool loadBoolArray(const char* elemName, int& arrayLength, bool* params);
/*	Loads float array. */
	bool loadFloatArray(const char* elemName, int& arrayLength, float* params);
/*	Loads string array. */
	bool loadStringArray(const char* elemName, int& arrayLength, char** params);

/*	Checks if the current element is empty. */
	bool isEmpty();
};

#endif // __APPSETTINGS_H__

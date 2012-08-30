#ifndef _DHANDLER
#define _DHANDLER

#include <string>
#include <curl/curl.h>

using std::string;

/*
 * A basic wrapper for cURL library
 * Singleton class
 */
class DownloadHandler {
private:
	static DownloadHandler *mInstance;

	// Constructor, takes in the base URL
	DownloadHandler(string);

	// Base Download URL, passed in the Constructor
	string baseURL;
	string oBuffer; 
	
	// cURL Stuff
	char errorBuffer[CURL_ERROR_SIZE];
	
	CURL *curl;
	CURLcode result;
	
	void initCURL();
		
	// CURLOPT_WRITEFUNCTION
	static int writer(char *, size_t, size_t, void *);
	
public:
	static DownloadHandler* getDownloadHandler();

	~DownloadHandler();
	
	bool success();
	string getError();

	/*
	 * The main Download Method, Takes in the URL and returns
	 * the downloaded data as a string. 
	 */
	string download(const char *);
};

#endif

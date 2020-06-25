#include <iostream>
#include <sstream>
#include <curl/curl.h>

static size_t httpCallback(char *contents, size_t size, size_t numMemb, void *userp, std::string towname) {
	std::ostringstream html;
	html << contents; std::string temp = "Max Temp", temp2= "Min Temp", temp3="Town:";
	//std::cout << "Town : " << html.str().substr(html.str().find(temp3) + 34, towname.size()) << std::endl;
	std::cout <<"Max Temp : "<< html.str().substr(html.str().find(temp)+ 34, 3)<<std::endl;
	std::cout <<"Min Temp : "<< html.str().substr(html.str().find(temp2)+ 34, 3)<<std::endl;
	//std::cout << html.str();
	return size * numMemb;
}

int main()
{
	CURL* curl; std::string input;
	CURLcode result;
	curl = curl_easy_init();
	std::cout << "Enter name of town : \n";
	std::cin >> input;
	if (curl)
	{
		curl_easy_setopt(curl, CURLOPT_URL, "http://www.meteo.go.ke/pages/fetch.php?town="+input);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, httpCallback, input);
		result = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}
	return 0;
}
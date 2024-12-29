#include <iostream>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

// Callback function to store data in a string
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

// Function to fetch weather data from OpenWeatherMap API
std::string getWeatherData(const std::string& city, const std::string& apiKey) {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    // Construct the API URL with the city and API key
    std::string url = "http://api.openweathermap.org/data/2.5/weather?q=" + city + "&appid=" + apiKey + "&units=metric";

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        // Set cURL options
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        // Perform the request
        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            std::cerr << "cURL error: " << curl_easy_strerror(res) << std::endl;
        }

        // Clean up cURL
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return readBuffer;
}

int main() {
    std::string city;
    std::string apiKey = "YOUR_API_KEY";  // Replace with your OpenWeatherMap API key

    std::cout << "Enter the city name: ";
    std::cin >> city;

    // Fetch weather data from OpenWeatherMap
    std::string data = getWeatherData(city, apiKey);

    // Parse JSON data using nlohmann::json
    try {
        json weatherData = json::parse(data);

        // Extract and display weather information
        std::string cityName = weatherData["name"];
        double temperature = weatherData["main"]["temp"];
        std::string weatherDescription = weatherData["weather"][0]["description"];

        std::cout << "Weather in " << cityName << ":\n";
        std::cout << "Temperature: " << temperature << "°C\n";
        std::cout << "Condition: " << weatherDescription << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error parsing JSON data: " << e.what() << std::endl;
    }

    return 0;
}
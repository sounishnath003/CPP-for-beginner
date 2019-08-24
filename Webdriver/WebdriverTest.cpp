#include<iostream>
#include<Webdriver/webdriverxx/webdriver.h>
using namespace std;
using namespace webdriverxx;

int main() {
    WebDriver firefox = Start(Firefox());
    firefox
        .Navigate("http://google.com")
        .FindElement(ByCss("input[name=q]"))
        .SendKeys("Hello, world!")
        .Submit();
    return 0;    
}
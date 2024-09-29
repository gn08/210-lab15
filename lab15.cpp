#include <iostream>
using namespace std;

class movie{
    private:
        string title;
        int year;
        string screen_writer;

    public:
        void set_title(){
            title = t;
        }

        void set_year(){
            year = y;
        }

        void set_screen_writer(){
            screen_writer = sw;
        }

        string get_title() const{
            return title;
        }

        int get_year() const{
            return year;
        }

        string get_screen_writer() const{
            return screen_writer;
        } 

        void print() const{
            cout << "Movie: " << title << endl;
            cout << "Year: " << year << endl;
            cout << "Screen writer: " << screen_writer << endl;
        }
};

int main(){
    vector<movie> movies;
    string title;
    int year;
    string screen_writer;
}
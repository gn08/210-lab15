#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Movie{
    private:
        string title;
        int year;
        string screen_writer;

    public:
        void set_title(const string& t){
            title = t;
        }

        void set_year(int y){
            year = y;
        }

        void set_screen_writer(const string& sw){
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
    vector<Movie> movies;
    string title;
    int year;
    string screen_writer;
    Movie temporary_movie;

    ifstream inputFile("input.txt");

    if (inputFile.is_open()){
        while (getline(inputFile, title) && inputFile >> year && inputFile.ignore() && getline(inputFile, screen_writer)){
            temporary_movie.set_title(title);
            temporary_movie.set_year(year);
            temporary_movie.set_screen_writer(screen_writer);

            movies.push_back(temporary_movie);
        }
        inputFile.close();
    } else {
        cout << "Can't open" << endl;
        return 1;
    }

    for (const Movie& movie : movies){
        movie.print();
        cout << endl;
    }

    return 0;
}
// COMSC-210 | Lab 15 | Gaby Filipova
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
    // set_title() sets a title to the movie
    // arguments: const string& t is the title of the movie
    // returns: void
        void set_title(const string& t){
            title = t;
        }
    // set_year() sets a year to the movie
    // arguments: int y is year released
    // returns: void
        void set_year(int y){
            year = y;
        }
    // set_screen_writer() sets a screen writer to the movie
    // arguments: const string& sw is the screen writer of the movie
    // returns: void
        void set_screen_writer(const string& sw){
            screen_writer = sw;
        }
    // get_title() gets the title for movie
    // return: string which is title of the movie
        string get_title() const{
            return title;
        }
     // get_year() gets the year for movie
    // return: string which is year of the movie
        int get_year() const{
            return year;
        }
     // get_screen_writer() gets the screen writer for movie
    // return: string which is screen writer of the movie
        string get_screen_writer() const{
            return screen_writer;
        } 
    // print() prints the movie iformation
    // returns: void
        void print() const{
            cout << "Movie: " << title << endl;
            cout << "Year: " << year << endl;
            cout << "Screen writer: " << screen_writer << endl;
        }
};

int main(){
    // vector storing movie stuff
    vector<Movie> movies;
    string title;
    int year;
    string screen_writer;
    //temporary movie location
    Movie temporary_movie;

    // open input file
    ifstream inputFile("input.txt");

    if (inputFile.is_open()){
        // information on file, set information
        while (getline(inputFile, title) && inputFile >> year && inputFile.ignore() && getline(inputFile, screen_writer)){
            temporary_movie.set_title(title);
            temporary_movie.set_year(year);
            temporary_movie.set_screen_writer(screen_writer);
        // add temporary movie
            movies.push_back(temporary_movie);
        }
        //close file
        inputFile.close();
    } else {
        //error message if not open
        cout << "Can't open" << endl;
        return 1;
    }
//print movies
    for (const Movie& movie : movies){
        movie.print();
        cout << endl;
    }

    return 0;
}
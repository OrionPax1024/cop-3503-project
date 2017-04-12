#include "gameskeleton.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

// use .insert() to put in line breaks
// std::string Print::textWrap(std::string line)
// {
//
// }

int countLines(std::string fileName)
{
  std::ifstream myFile(fileName + ".txt");
  // skips empty lines (I think)
  return std::count( std::istreambuf_iterator<char>(myFile), std::istreambuf_iterator<char>(), '\n');
}

int Input::readInput(int lineCount)
{
  int c;
  while (true)
  {
    std::cin >> c;
    if (std::cin.good())
    {
      if (c < lineCount - 1 && c >= 0)
      {
        return c;
      }
      else
      {
        std::cout << "Error: Menu option out of range. Try again." << std::endl;
      }
    }
    else
    {
      std::cout << "Error: Invalid menu option. Try again." << std::endl;
      std::cin.clear();
      std::cin.ignore(1000, '\n');
    }
  }
}

std::string Scene::sceneloop(std::string start)
{
  return "GAME OVER";
}

std::string Trolls::sceneloop(std::string start)
{
  Input input;
  int command;

  std::string currentFrame = start;
  std::string line;

  int lineCount;
  std::ifstream file;

  int hideCount = 0; // counts number of times player chooses to hide

  bool go = true;
  while (go)
  {
    if (hideCount > 3)
    {
      file.open("TROLLS_HIDE_SUCCESS.txt");
      std::getline(file, line);
      std::cout << '\n' << line << std::endl;
      go = false;
    }
    else
    {
      file.open(currentFrame + ".txt"); //TODO add exception handling
      std::getline(file, line);
      std::cout << '\n' << line << std::endl;

      lineCount = countLines(currentFrame);
      // std::cout << "lineCount: " << lineCount << std::endl;

      if (lineCount < 3 || line.find("GAME OVER") != std::string::npos) // there is no next scene or there is only one next scene
      {
        go = false;
      }
      else
      {
        command = input.readInput(lineCount);
        for (int i = -1; i < command; i++)
        {
          std::getline(file, line);
        }

        currentFrame = line;
        std::cout << currentFrame << std::endl;
        file.close();

        if (currentFrame.compare("TROLLS_HIDE") == 0)
        {
          hideCount++;
          std::cout << hideCount << std::endl;
        }
      }
    }

  }

  std::getline(file, line);

  return line;

}

std::string Junction::sceneloop(std::string start)
{
  Input input;
  int command;

  std::string currentFrame = start;
  std::string line;

  int lineCount;
  std::ifstream file;

  bool go = true;
  while (go)
  {
      file.open(currentFrame + ".txt"); //TODO add exception handling
      std::getline(file, line);
      std::cout << '\n' << line << std::endl;

      lineCount = countLines(currentFrame);
      // std::cout << "JUNCTION lineCount: " << lineCount << std::endl;


      if (lineCount < 3 || line.find("GAME OVER") != std::string::npos) // there is no next scene or there is only one next scene
      {
        std::getline(file, line);
        currentFrame = line;
        go = false;
      }
      else
      {
        command = input.readInput(lineCount);
        if (command == 1) go = false;
        for (int i = -1; i < command; i++)
        {
          std::getline(file, line);
        }

        currentFrame = line;
        file.close();
      }

  }

  return currentFrame;

}

std::string Dragon::sceneloop(std::string start)
{
  Input input;
  int command;

  std::string currentFrame = start;
  std::string line;

  int lineCount;
  std::ifstream file;

  bool go = true;
  while (go)
  {
      file.open(currentFrame + ".txt"); //TODO add exception handling
      std::getline(file, line);
      std::cout << '\n' << line << std::endl;

      lineCount = countLines(currentFrame);
      // std::cout << "JUNCTION lineCount: " << lineCount << std::endl;


      if (lineCount < 3 || line.find("GAME OVER") != std::string::npos) // there is no next scene or there is only one next scene
      {
        std::getline(file, line);
        currentFrame = line;
        go = false;
      }
      else
      {
        command = input.readInput(lineCount);
        if (command == 1) go = false;
        for (int i = -1; i < command; i++)
        {
          std::getline(file, line);
        }

        currentFrame = line;
        file.close();
      }

  }

  return currentFrame;

}

std::string Castle::sceneloop(std::string start)
{
  Input input;
  int command;

  std::string currentFrame = start;
  std::string line;

  int lineCount;
  std::ifstream file;

  bool go = true;
  while (go)
  {
      file.open(currentFrame + ".txt"); //TODO add exception handling
      std::getline(file, line);
      std::cout << '\n' << line << std::endl;

      lineCount = countLines(currentFrame);
      // std::cout << "JUNCTION lineCount: " << lineCount << std::endl;


      if (lineCount < 3 || line.find("GAME OVER") != std::string::npos) // there is no next scene or there is only one next scene
      {
        std::getline(file, line);
        currentFrame = line;
        go = false;
      }
      else
      {
        command = input.readInput(lineCount);
        if (command == 1) go = false;
        for (int i = -1; i < command; i++)
        {
          std::getline(file, line);
        }

        currentFrame = line;
        file.close();
      }

  }

  return currentFrame;

}

std::string Sphinx::sceneloop(std::string start)
{
  std::string line;
  std::ifstream file;

  file.open(start + ".txt"); //TODO add exception handling
  std::getline(file, line);
  std::cout << '\n' << line << std::endl;
  file.close();

  file.open("SPHINX_RIDDLE.txt"); //TODO add exception handling
  std::getline(file, line);
  std::cout << '\n' << line << std::endl;

  std::string correctAnswer;
  std::getline(file, correctAnswer);
  file.close();

  int attemptCount = 0;
  std::string attempt;

  bool go = true;
  while (go)
  {
    std::cin >> attempt;
    attemptCount++;

    if (attempt.compare(correctAnswer) == 0)
    {
      std::cout << "Correct!" << std::endl;
      file.open("SPHINX_SUCCESS.txt"); //TODO add exception handling
      std::getline(file, line);
      std::cout << '\n' << line << std::endl;
      go = false;
    }
    else
    {
      if (attemptCount > 2)
      {
        std::cout << "You have failed for the last time." << std::endl;
        return "GAME OVER";
      }
      else
      {
        std::cout << "Wrong answer. " << 3 - attemptCount << " attempts left." << std::endl;
        std::cout << line << std::endl;

        std::cin.clear();
        std::cin.ignore(1000, '\n');
      }
    }

  }

  std::getline(file, line);
  file.close();

  return line;

}

void Game::gameloop()
{
  std::string current = start;
  Scene* scene;
  while (current.compare("GAME OVER") != 0)
  {
    if (current.compare("TROLLS_START") == 0)
    {
      scene = new Trolls();
    }
    else if (current.compare("SPHINX_START") == 0)
    {
      scene = new Sphinx();
    }
    else if (current.compare("DRAGON_START") == 0)
    {
      scene = new Dragon();
    }
    else if (current.compare("CASTLE_START") == 0)
    {
      scene = new Castle();
    }
    else
    {
      scene = new Junction();
    }
    std::cout << "gameloop current: " << current << std::endl;
    current = scene->sceneloop(current); //TODO redundant current
    std::cout << "gameloop current: " << current << std::endl;

  }
}

int main() {

  // Scene scene("TROLLS_START");
  // scene.sceneloop(scene.getStart());

  Game game("START");
  game.gameloop();

  return 0;
}

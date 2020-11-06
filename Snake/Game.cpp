#include <iostream>
#include <conio.h>
#include <stdlib.h>

#include "Object.h"
#include "Snake.h"

void Draw(int height, int width, Object fruit, Snake snake)
{
    system("cls");
    // Top
    for (int i = 0; i < width+2; i++)
    {
        std::cout << "#";
    }
    std::cout << std::endl;

    // Canvas
    for (int i = 0; i < height; i++)
    {
        std::cout << "#";
        for (int j = 0; j < width; j++)
        {
            bool print = false;
            for (int k = 0; k < snake.getBody().size(); k++)
            {
                // If snake body
                if (j == snake.getBody()[k].getX()
                    && i == snake.getBody()[k].getY())
                {
                    std::cout << snake.getSpriteBody();
                    print = true;
                    break;
                }
            }
            if (print)
            {
                continue;
            }
            // If fruit
            else if (j == fruit.getX() && i == fruit.getY())
            {
                std::cout << "F";
            }
            // If snake head
            else if (j == snake.getX() && i == snake.getY())
            {
                std::cout << snake.getSpriteHead();
            }
            else
            {
                std::cout << " ";
            }
        }
        std::cout << "#" << std::endl;
    }
    
    // Bottom
    for (int i = 0; i < width + 2; i++)
    {
        std::cout << "#";
    }
}

void ControlSnake(Snake &snake)
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'w':
            snake.Move(Direction::UP);
            break;
        case 's':
            snake.Move(Direction::DOWN);
            break;
        case 'a':
            snake.Move(Direction::LEFT);
            break;
        case 'd':
            snake.Move(Direction::RIGHT);
            break;
        }
    }
    else
    {
        snake.Move(snake.getDirection());
    }
    snake.MoveBody();
}

bool isCollideFruit(Object fruit, Snake snake)
{
    return (fruit.getX() == snake.getX() && fruit.getY() == snake.getY());
}

bool isCollideWall(Snake snake, int height, int width)
{
    return (snake.getX() < 0 || snake.getY() < 0
        || snake.getY() >= height || snake.getX() >= width);
}

bool isRestart()
{
    while (true)
    {
        std::string choice;
        std::cout << "Try again? (Y/N): ";
        std::cin >> choice;
        if (choice == "Y" || choice == "y")
            return true;
        else if (choice == "N" || choice == "n")
            return false;
        else
            std::cout << "Please enter Y or N." << std::endl;
    }
}

int main()
{
    do {
        bool gameOver = false;
        const int height = 24;
        const int width = 48;
        int score = 0;
        Object fruit(rand() % width, rand() % height);
        Snake snake;
        while (!gameOver)
        {
            Draw(height, width, fruit, snake);
            ControlSnake(snake);
            if (isCollideFruit(fruit, snake))
            {
                snake.Grow();
                score++;
                fruit.setX(rand() % width);
                fruit.setY(rand() % height);
            }
            else if (isCollideWall(snake, height, width) || snake.isCollideSelf())
            {
                gameOver = true;
            }
            std::cout << std::endl << "Score: " << score;
        }
        std::cout << std::endl << "Game over! ";
    } while (isRestart());
}

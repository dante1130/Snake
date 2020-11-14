import sys
sys.path.append(".")
import pygame
from random import randint
from Snake.classes.direction import Direction
from Snake.classes.object import Object
from Snake.classes.snake import Snake


def main():
    # Initialize pygame
    pygame.init()
    running = True

    # Create window with width and height
    width = 640
    height = 512
    screen = pygame.display.set_mode((width, height))
    clock = pygame.time.Clock()
    
    pygame.display.set_caption("Snake")

    # sprites
    fruit_sprite = pygame.image.load('Snake/sprites/apple.png')
    snake_sprite = pygame.image.load('Snake/sprites/snake.png')
    background = pygame.image.load('Snake/sprites/bg.png')

    # Instantiate objects
    fruit = Object(randint(0, 19) * 32, randint(0, 14) * 32, fruit_sprite)
    snake = Snake(32, 32, snake_sprite)
    score = 0
    font = pygame.font.Font('freesansbold.ttf', 32)


    # Game loop
    while running:
        clock.tick(10)
        screen.fill((0, 0, 0))
        #drawGrid(width,height,screen)
        screen.blit(background, (0, 0))

        # Handle events
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            if event.type == pygame.KEYDOWN:
                moveSnake(event, snake)


        snake.moveDirection()
        snake.moveBody()

         # Collision detection
        if isCollideWall(width, height, snake) or snake.isCollideSelf():
            break
        elif isCollideFruit(snake, fruit):
            score += 1
            fruit.x = randint(0, 19) * 32
            fruit.y = randint(0, 14) * 32
            snake.grow()

        drawObject(snake, screen)
        drawObjectArr(snake.body, screen)
        drawObject(fruit, screen)
        drawScore(score, font, screen)
        pygame.display.update()

       
def drawObject(object, screen):
    screen.blit(object.sprite, (object.x, object.y))

def drawObjectArr(object_arr, screen):
    for object in object_arr:
        screen.blit(object.sprite, (object.x, object.y))

def drawScore(score, font, screen):
    scoreR = font.render("Score: " + str(score), True, (255, 255, 255))
    screen.blit(scoreR, (480, 480))

def drawGrid(width, height, screen):
    blockSize = 32 #Set the size of the grid block
    for x in range(width):
        for y in range(height):
            rect = pygame.Rect(x * blockSize, y * blockSize,
                               blockSize, blockSize)
            pygame.draw.rect(screen, (200, 200, 200), rect, 1)


def isCollideWall(width, height, snake):
    return (snake.x >= width or snake.y >= height - 32 or snake.x < 0 or snake.y < 0)

def isCollideFruit(snake, fruit):
    return (snake.x == fruit.x and snake.y == fruit.y)


def moveSnake(event, snake):
    if event.key == pygame.K_UP and snake.direction != Direction.DOWN:
        snake.move(Direction.UP)
    if event.key == pygame.K_DOWN and snake.direction != Direction.UP:
        snake.move(Direction.DOWN)
    if event.key == pygame.K_LEFT and snake.direction != Direction.RIGHT:
        snake.move(Direction.LEFT)
    if event.key == pygame.K_RIGHT and snake.direction != Direction.LEFT:
        snake.move(Direction.RIGHT)


if __name__ == "__main__":
    main()

from Snake.classes.direction import Direction
from Snake.classes.object import Object


class Snake(Object):
    prev_x = 0
    prev_y = 0
    direction = Direction.RIGHT
    body = []
    
    def createBody(self, x, y):
        self.body.append(Object(x, y, self.sprite))
            

    def grow(self):
        if not self.body:
            Snake.createBody(self, self.x, self.y)
        else:
            Snake.createBody(self, self.body[-1].x, self.body[-1].y)

    def moveBody(self):
        if (not self.body): return
        temp1_x = self.body[0].x
        temp1_y = self.body[0].y
        self.body[0].x = self.prev_x
        self.body[0].y = self.prev_y
        for i in range(1, len(self.body)):
            temp2_x = self.body[i].x
            temp2_y = self.body[i].y
            self.body[i].x = temp1_x
            self.body[i].y = temp1_y
            temp1_x = temp2_x
            temp1_y = temp2_y

    def move(self, direction):

        if direction == Direction.UP:
            self.direction = Direction.UP
        elif direction == Direction.DOWN:
            self.direction = Direction.DOWN
        elif direction == Direction.LEFT:
            self.direction = Direction.LEFT
        else:
            self.direction = Direction.RIGHT

    def isCollideSelf(self):
        for body in self.body:
            if self.x == body.x and self.y == body.y:
                return True
        return False

    def moveDirection(self):
        speed = 32
        x = 0
        y = 0
        if self.direction == Direction.UP:
            y = -speed
        elif self.direction == Direction.DOWN:
            y = speed
        elif self.direction == Direction.LEFT:
            x = -speed
        else:
            x = speed

        self.prev_x = self.x
        self.prev_y = self.y
        self.x += x
        self.y += y
class Robot:

    def __init__(self, givenName, givenColour, givenWeight):
        self.name = givenName
        self.colour = givenColour
        self.weight = givenWeight

    def introduce_self(self):
        print("My name is " + self.name)

r1 = Robot("Tom", "red", 30)

r2 = Robot("Jerry", "blue", 40)

r1.introduce_self()
r2.introduce_self()
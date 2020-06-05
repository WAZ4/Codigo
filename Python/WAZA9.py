class Robot:

    def __init__(self, givenName, givenColour, givenWeight):
        self.name = givenName
        self.colour = givenColour
        self.weight = givenWeight

    def introduce_self(self):
        print("My name is " + self.name)

r1 = Robot("Tom", "red", 30)

r2 = Robot("Jerry", "blue", 40)

class Person:

    def __init__(self, n, p, i):
        self.nanem = n
        self.personality = p
        self.isSitting = i

    def sit_down(self):
        self.isSitting = True
    
    def stand_up(self):
        self.isSitting = False
        
p1 = Person("Alice", "agressive", False)
p2 = Person("Becky", "agressive", True)

p1.robot_owned = r2
p2.robot_owned = r1

p1.robot_owned.introduce_self()



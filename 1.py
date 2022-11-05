class RPGCharacter: 
    def __init__(self):
        self.action = 'Doing Nothing'
    def act(self):
        print(self.action)
class Fighter(RPGCharacter):
    def __init__(self):
        self.action = 'Fight'

class Cleric(RPGCharacter):
    def __init__(self):
        self.action = 'Heal'

class Paladin(Fighter,Cleric):
    pass

me = Paladin()
me.act()
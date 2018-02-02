class Faculty(object):
    id = 0
    name = ""

    def __str__(self):
        return "%d) %s" % ( self.id, self.name)

    def __init__(self, id, name):
        self.id = id
        self.name = name

    def __eq__(self, other):
        return self.id == other.id

    def set_name(self, name):
        self.name = name

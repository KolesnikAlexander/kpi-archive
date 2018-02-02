class Group(object):
    id = 0
    name = ""
    faculty_id = 0

    def __str__(self):
        return "%d) %s" % (self.id, self.name)

    def __init__(self, group_id, name, faculty_id, ):
        self.id = group_id
        self.name = name
        self.faculty_id = faculty_id

    def __eq__(self, other):
        return (self.id == other.id) and (self.faculty_id == other.faculty_id)

    def set_faculty_id(self, id):
        self.faculty_id = int(id)

    def set_group_name(self, name):
        self.name = name

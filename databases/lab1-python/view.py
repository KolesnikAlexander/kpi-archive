def main_view():
    print("    MAIN MENU")
    print("    FACULTIES")
    print("1)View faculties")
    print("2)Add faculty")
    print("3)Delete faculty")
    print("4)Edit faculty")
    print("5)Faculties with max number of groups")
    print("    GROUPS")
    print("6)View groups")
    print("7)Add group")
    print("8)Delete group")
    print("9)Edit group")
    print("    SAVE")
    print("0)Save")
    print("10)Save and Exit")


# VIEW FACULTIES

def view_faculties(faculties_list):
    print ("    VIEW FACULTIES")
    print_faculties(faculties_list)


def print_faculties(faculties_list):
    for faculty in faculties_list:
        print str(faculty.id)+')'+faculty.name


# VIEW GROUPS

def view_all(groups, faculties):
    print "     VIEW ALL"
    print "-------------------------"
    print "ID GROUP   |   ID FACULTY"
    print "-------------------------"
    for group in groups:
        faculty = find_faculty(group, faculties)
        print str(group), "  |  ", str(faculty)


# COMMON

def faculty():
    print ("Faculty: "),


def group():
    print ("Group: "),


def faculty_dnot_exist():
    print ("Denied: faculty does not exist"),


def new_faculty():
    print ("New faculty: "),


def new_group():
    print ("New group: "),


def print_message(message):
    print (message)

# ADD FACULTY


def add_faculty():
    print ("    ADD FACULTY")


def faculty_alrdy_exists():
    print ("Denied: faculty already exists")


def faculty_added():
    print ("Faculty successfully added")

# ADD GROUP


def add_group():
    print ("    ADD GROUP")


def group_created():
    print ("Group successfully created "),


def grp_alrdy_exists():
    print ("Denied: group already exists "),


# DELETE FACULTY

def delete_faculty():
    print ("    DELETE FACULTY")
    print ("    (all groups of the faculty will be removed)")


def faculty_deleted():
    print ("Faculty successfully deleted")

# DELETE GROUP


def delete_group():
    print ("    DELETE GROUP")


def grp_dnot_exist():
    print ("Denied: group does not exist"),


def group_deleted():
    print ("Group successfully deleted")


# UPDATE GROUP


def update_group():
    print ("    UPDATE GROUP")


def group_updated():
    print ("Group successfully updated")

# UPDATE FACULTY


def update_faculty():
    print ("    UPDATE FACULTY")


def faculty_updated():
    print ("Faculty successfully updated")


# FILTER FACULTY

def filter_faculty():
    print ("    FILTER FACULTY")


def print_filtered_faculties(quantity, faculties_list):
    print "Max quantity of groups: ", quantity
    print ("Faculties: ")
    print_faculties(faculties_list)

# SAVE


def save():
    print ("Data saved")

# ASSISTANT


def find_faculty(group, faculties):
    for faculty in faculties:
        if group.faculty_id == faculty.id:
            return faculty



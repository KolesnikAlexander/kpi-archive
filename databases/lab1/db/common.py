import os
import pickle

FACULTIES_PATH = 'db/faculties.pkl'
GROUPS_PATH = 'db/groups.pkl'


faculties = []
groups = []
faculties_count = 0
groups_count = 0


def load_db():
    prepare_files()
    load_faculties()
    load_groups()
    set_faculties_count()
    set_groups_count()


def get_faculties():
    global faculties
    return faculties


def get_groups():
    global groups
    return groups


def set_faculties_count():
    global faculties_count
    faculties_count = 0
    for faculty in faculties:
        if faculty.id >= faculties_count:
            faculties_count = faculty.id + 1


def set_groups_count():
    global groups_count
    groups_count = 0
    for group in groups:
        if group.id >= groups_count:
            groups_count = group.id + 1


def prepare_files():
    if not file_exists(FACULTIES_PATH):
        open(FACULTIES_PATH, 'wb+').close()
    if not file_exists(GROUPS_PATH):
        open(GROUPS_PATH, 'wb+').close()


def load_faculties():
    if not os.stat(FACULTIES_PATH).st_size == 0:  # if file is not empty
        inp = open(FACULTIES_PATH, 'rb')
        global faculties
        faculties = pickle.load(inp)
        inp.close()
    else:
        faculties = []


def load_groups():
    global groups
    if not os.stat(GROUPS_PATH).st_size == 0:  # if file is not empty
        inp = open(GROUPS_PATH, 'rb')
        groups = pickle.load(inp)
        inp.close()
    else:
        groups = []


def write_db():
    global groups
    global faculties

    out = open(FACULTIES_PATH, 'wb')
    pickle.dump(faculties, out, -1)
    out.close()

    out = open(GROUPS_PATH, 'wb')
    pickle.dump(groups, out, -1)
    out.close()


def file_exists(path):
    return os.path.isfile(path)



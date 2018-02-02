# Faculty
from db import faculty
from db import group


def create_faculty(name):
    return faculty.create_faculty(name)


def read_faculties():
    return faculty.read_faculties()


def update_faculty(name, new_name):
    id = faculty.get_faculty_id_by_name(name)
    return faculty.update_faculty(id, new_name)


def delete_faculty(name):
    fac_id = faculty.get_faculty_id_by_name(name)
    return faculty.delete_faculty(fac_id)


def faculty_exists(name):
    return faculty.faculty_exists_name(name)


def filter_faculty():
        return faculty.filter_faculty()

# Group


def create_group(name, faculty_name):
    fac_id = faculty.get_faculty_id_by_name(faculty_name)
    return group.create_group(name, fac_id)


def read_groups():
    return group.read_groups()


def update_group(faculty_name, group_name, new_faculty_name, new_group_name):
    faculty_id = faculty.get_faculty_id_by_name(faculty_name)
    group_id = group.get_group_id_by_name(group_name)
    new_faculty_id = faculty.get_faculty_id_by_name(new_faculty_name)
    return group.update_group(group_id, faculty_id, new_faculty_id, new_group_name)


def delete_group(name, faculty_name):
    fac_id = faculty.get_faculty_id_by_name(faculty_name)
    group_id = group.get_group_id_by_name(name)
    return group.delete_group(group_id, fac_id)


def group_exists(name, faculty_id):
    return group.group_exists_name(name, faculty_id)

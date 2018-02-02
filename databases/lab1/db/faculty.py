from db import common
from entity.faculty import Faculty


def create_faculty(name):
    faculties = common.get_faculties()
    if not faculty_exists_name(name):
        faculties.append(Faculty(common.faculties_count, name))
        common.faculties_count += 1
        return {"code": 0, "message": "OK"}
    else:
        return {"code": -1, "message": "Faculty exists"}


def read_faculties():
    faculties = common.get_faculties()
    return faculties


def update_faculty(id, new_name):
    faculties = common.get_faculties()
    if faculty_exists_id(id):
        if not faculty_exists_name(new_name):
            faculty_index = faculties.index(Faculty(id, "nop"))
            faculty = faculties[faculty_index]
            faculty.set_name(new_name)
            return {"code": 0, "message": "OK"}
        else:
            return {"code": -1, "message": "Faculty with this name already exists"}
    else:
        return {"code": -1, "message": "Faculty does not exist"}


def delete_faculty(id):
    faculties = common.get_faculties()
    if faculty_exists_id(id):
        from db.group import delete_groups_of_faculty
        delete_groups_of_faculty(id)
        faculties.remove(Faculty(id, "nop"))
        return {"code": 0, "message": "OK"}
    else:
        return {"code": -1, "message": "Faculty with this id does not exist"}


def get_faculty_id_by_name(name):
    faculties = common.get_faculties()
    for faculty in faculties:
        if faculty.name == name:
            return faculty.id
    return None


def faculty_exists_name(name):
    return not get_faculty_id_by_name(name) is None


def faculty_exists_id(id):
    faculties = common.get_faculties()
    return Faculty(id, "nop") in faculties


def filter_faculty(): # max number of groups
    fac_list = faculties_with_quantity_of_groups()
    return filter_all(fac_list)


def faculties_with_quantity_of_groups():
    faculties = common.get_faculties()
    groups = common.get_groups()
    result = {}
    for faculty in faculties:
        faculty_quantity = 0
        for group in groups:
            if group.faculty_id == faculty.id:
                faculty_quantity += 1
        result.update({faculty: faculty_quantity})
    return result


def filter_all(faculty_quantity_dict):
    max_groups = 0
    max_groups_faculties = []

    for fac, num_of_groups in faculty_quantity_dict.iteritems():
        if num_of_groups == max_groups:
            max_groups_faculties.append(fac)
        elif num_of_groups > max_groups:
            max_groups_faculties = []
            max_groups_faculties.append(fac)
            max_groups = num_of_groups

    return {"quantity": max_groups, "faculties": max_groups_faculties}

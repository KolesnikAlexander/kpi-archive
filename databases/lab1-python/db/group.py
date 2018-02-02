from db import common, faculty
from entity.group import Group


def create_group(name, faculty_id):
    groups = common.get_groups()
    if faculty.faculty_exists_id(faculty_id):
        if not group_exists_name(name, faculty_id):
            groups.append(Group(common.groups_count, name, faculty_id))
            common.groups_count += 1
            return {"code": 0, "message": "OK"}
        else:
            return {"code": -1, "message": "Group already exists"}
    else:
        return {"code": -1, "message": "Faculty does not exist"}


def read_groups():
    groups = common.get_groups()
    return groups


def update_group(group_id, faculty_id, new_faculty_id, new_group_name):
    groups = common.get_groups()
    if faculty.faculty_exists_id(faculty_id):
        if group_exists_id(group_id, faculty_id):
            if faculty.faculty_exists_id(new_faculty_id):
                if not group_exists_name(new_group_name, new_faculty_id):
                    group_index = groups.index(Group(group_id, "nop", faculty_id))
                    group = groups[group_index]
                    group.set_faculty_id(new_faculty_id)
                    group.set_group_name(new_group_name)
                    return {"code": 0, "message": "OK"}
                else:
                    return {"code": -1, "message": "Group with this name already exist"}
            else:
                return {"code": -1, "message": "New faculty does not exist"}
        else:
            return {"code": -1, "message": "Group does not exist"}
    else:
        return {"code": -1, "message": "Faculty does not exist"}


def delete_group(id, faculty_id):
    groups = common.get_groups()
    if group_exists_id(id, faculty_id):
        groups.remove(Group(id, "nop", faculty_id))
        return {"code": 0, "message": "OK"}
    else:
        return {"code": -1, "message": "Group does not exist"}


def group_exists_name(name, faculty_id):
    groups = common.get_groups()
    for group in groups:
        if (group.name == name) and (group.faculty_id == faculty_id):
            return True
    return False


def group_exists_id(id, faculty_id):
    groups = common.get_groups()
    return Group(id, "nop", faculty_id) in groups


def delete_groups_of_faculty(faculty_id):
    groups = common.get_groups()
    out = False
    while not out:
        out = True
        for group in groups:
            if group.faculty_id == faculty_id:
                groups.remove(group)
                out = False
                break


def get_group_id_by_name(name):
    groups = common.get_groups()
    for group in groups:
        if group.name == name:
            return group.id
    return None

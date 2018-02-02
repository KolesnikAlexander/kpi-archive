import sys

import dao
import view
from db import common
from view import view_all, main_view

# MAIN


def main_controller():
    main_view()
    inp = int(raw_input())
    if inp == 1:
        view_faculties()
    elif inp == 2:
        add_faculty()
    elif inp == 3:
        delete_faculty()
    elif inp == 4:
        update_faculty()
    elif inp == 5:
        filter_faculty()
    elif inp == 6:
        view_groups()
    elif inp == 7:
        add_group()
    elif inp == 8:
        delete_group()
    elif inp == 9:
        update_group()
    elif inp == 0:
        save()
    elif inp == 10:
        save_and_exit()
    else:
        print ("Unknown command")
    print

# VIEW ALL


def view_faculties():
    faculties_list = dao.read_faculties()
    view.view_faculties(faculties_list)


def view_groups():
    groups = dao.read_groups()
    faculties = dao.read_faculties()
    view_all(groups, faculties)

# ADD FACULTY


def add_faculty():
    view.add_faculty()
    add_faculty_inp_name()


def add_faculty_inp_name():
    view.faculty()
    inp = raw_input()

    resp = dict(dao.create_faculty(inp)).get("code")
    if resp == -1:
        view.faculty_alrdy_exists()
    else:
        view.faculty_added()

# ADD GROUP


def add_group():
    view.add_group()
    add_group_inp_faculty()


def add_group_inp_faculty():
    view.faculty()
    fac_name = raw_input()

    if dao.faculty_exists(fac_name):
        add_group_inp_group(fac_name)
    else:
        view.faculty_dnot_exist()


def add_group_inp_group(fac_name):
    view.group()
    group_name = raw_input()
    resp = dao.create_group(group_name, fac_name).get("code")
    if resp == -1:
        view.grp_alrdy_exists()
    else:
        view.group_created()


# DELETE FACULTY


def delete_faculty():
    view.delete_faculty()
    delete_faculty_inp_name()


def delete_faculty_inp_name():
    view.faculty()
    inp = raw_input()

    resp = dict(dao.delete_faculty(inp)).get("code")
    if resp == -1:
        view.faculty_dnot_exist()
    else:
        view.faculty_deleted()


# DELETE GROUP


def delete_group():
    view.delete_group()
    view.faculty()
    fac_name = raw_input()

    if dao.faculty_exists(fac_name):
        delete_group_input_group(fac_name)
    else:
        view.faculty_dnot_exist()


def delete_group_input_group(fac_name):
    view.group()
    group_name = raw_input()
    resp = dao.delete_group(group_name, fac_name).get("code")
    if resp == -1:
        view.grp_dnot_exist()
    else:
        view.group_deleted()

# UPDATE GROUP


def update_group():
    view.update_group()

    view.faculty()
    faculty = raw_input()

    view.group()
    group = raw_input()

    view.new_faculty()
    new_faculty = raw_input()

    view.new_group()
    new_group = raw_input()

    resp = dao.update_group(faculty, group, new_faculty, new_group)
    if resp.get("code") == -1:
        view.print_message(resp.get("message"))
    else:
        view.group_updated()


def update_faculty():
    view.update_faculty()

    view.faculty()
    faculty = raw_input()

    view.new_faculty()
    new_faculty = raw_input()

    resp = dao.update_faculty(faculty, new_faculty)
    if resp.get("code") == -1:
        view.print_message(resp.get("message"))
    else:
        view.faculty_updated()


# SAVE

def save():
    common.write_db()
    view.save()


# SAVE AND EXIT

def save_and_exit():
    save()
    sys.exit()


# FILTER FACULTY
def filter_faculty():
    view.filter_faculty()
    quantity_and_faculties = dao.filter_faculty()
    quantity = quantity_and_faculties.get("quantity")
    faculties = quantity_and_faculties.get("faculties")
    view.print_filtered_faculties(quantity, faculties)

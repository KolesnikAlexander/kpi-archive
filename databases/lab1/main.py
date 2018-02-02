from controller import main_controller
from db import common


common.load_db()
while True:
    main_controller()

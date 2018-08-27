#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# -*- Author:Seiya -*-


SERVER_HEADER = "http://192.168.21.11:8000"


ERROR_CODE = {
    "0": "ok",
    # Users error code
    "1001": "入参非法",
    "1002": "用户已注册，请直接登录",
    "2001": "上传图片不能为空",
    "1003": "用户尚未注册，请先注册"
}


from sqlalchemy import create_engine
from sqlalchemy.ext.declarative import declarative_base
engine = create_engine('mysql://root:pwd@demo@192.168.21.11:3306/demo?charset=utf8', encoding="utf8", echo=False)
BaseDB = declarative_base()

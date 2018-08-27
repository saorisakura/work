#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# -*- Author:Seiya -*-
from __future__ import unicode_literals
from .users_views import (
    RegistHandler,
    LoginHandler
)

urls = [
    # 从 /users/regist 过来的请求，将调用 users_views 里面的 RegistHandle 类
    (r'regist', RegistHandler),
    (r'regist', LoginHandler)
]

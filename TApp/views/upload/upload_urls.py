#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# -*- Author:Seiya -*-
from __future__ import unicode_literals
from .upload_views import (
    UploadFileHandle
)

urls = [
    # 从/upload/file过来的请求，将调用upload_views里面的UploadFileHandle类
    (r'file', UploadFileHandle)
]

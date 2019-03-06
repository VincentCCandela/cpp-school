#!/usr/bin/python
# EASY-INSTALL-ENTRY-SCRIPT: 'term2048==0.2.6','console_scripts','term2048'
__requires__ = 'term2048==0.2.6'
import re
import sys
from pkg_resources import load_entry_point

if __name__ == '__main__':
    sys.argv[0] = re.sub(r'(-script\.pyw?|\.exe)?$', '', sys.argv[0])
    sys.exit(
        load_entry_point('term2048==0.2.6', 'console_scripts', 'term2048')()
    )

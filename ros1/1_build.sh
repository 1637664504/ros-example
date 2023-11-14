echo "参数 $#"

function first_build()
{
    echo "first_build"
    catkin_make -DCATKIN_WHITELIST_PACKAGES="common"
    catkin_make -DCATKIN_WHITELIST_PACKAGES=""
}

function build_module()
{
    module=$1
    echo "build module $module"
    catkin_make -DCATKIN_WHITELIST_PACKAGES="$module"
}

function build_all()
{
    echo "build all"
    catkin_make -DCATKIN_WHITELIST_PACKAGES=""
}

if [ $# -gt 0 ]; then
    cmd=$1
    if [ $cmd == 1 ]; then
        first_build
    else
        build_module $cmd
    fi
else
    build_all
fi

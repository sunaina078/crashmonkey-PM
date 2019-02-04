Last login: Mon Feb  4 13:26:02 on console
wireless-10-147-127-34:~ sunaina$ ssh lillian@chennai.csres.utexas.edu
lillian@chennai.csres.utexas.edu's password: 
Welcome to Ubuntu 16.04.4 LTS (GNU/Linux 4.13.0+ x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage

170 packages can be updated.
0 updates are security updates.

New release '18.04.1 LTS' available.
Run 'do-release-upgrade' to upgrade to it.

Last login: Sun Feb  3 21:11:38 2019 from 10.147.127.34
lillian@pandian-utcs:~$ ls
examples.desktop  research
lillian@pandian-utcs:~$ cd research/
lillian@pandian-utcs:~/research$ ls
panda  panda_scratchpad  snapshot_dev_git  vm.img
lillian@pandian-utcs:~/research$ cd snapshot_dev_git/
lillian@pandian-utcs:~/research/snapshot_dev_git$ ls
crashmonkey-PM  panda
lillian@pandian-utcs:~/research/snapshot_dev_git$ cd crashmonkey-PM/
lillian@pandian-utcs:~/research/snapshot_dev_git/crashmonkey-PM$ ls
launch_headless.sh  launch.sh  Makefile  out.log  personal_plugins  README.MD  scripts  src  workload  workloads  wt.out
lillian@pandian-utcs:~/research/snapshot_dev_git/crashmonkey-PM$ cd personal_plugins/
lillian@pandian-utcs:~/research/snapshot_dev_git/crashmonkey-PM/personal_plugins$ cd panda/plugins/writetracker/
lillian@pandian-utcs:~/research/snapshot_dev_git/crashmonkey-PM/personal_plugins/panda/plugins/writetracker$ vim writetracker.cpp 
lillian@pandian-utcs:~/research/snapshot_dev_git/crashmonkey-PM/personal_plugins/panda/plugins/writetracker$ cd ../../../../
lillian@pandian-utcs:~/research/snapshot_dev_git/crashmonkey-PM$ git push
warning: push.default is unset; its implicit value has changed in
Git 2.0 from 'matching' to 'simple'. To squelch this message
and maintain the traditional behavior, use:

  git config --global push.default matching

To squelch this message and adopt the new behavior now, use:

  git config --global push.default simple

When push.default is set to 'matching', git will push local branches
to the remote branches that already exist with the same name.

Since Git 2.0, Git defaults to the more conservative 'simple'
behavior, which only pushes the current branch to the corresponding
remote branch that 'git pull' uses to update the current branch.

See 'git help config' and search for 'push.default' for further information.
(the 'simple' mode was introduced in Git 1.7.11. Use the similar mode
'current' instead of 'simple' if you sometimes use older versions of Git)

fatal: You are not currently on a branch.
To push the history leading to the current (detached HEAD)
state now, use

    git push origin HEAD:<name-of-remote-branch>

lillian@pandian-utcs:~/research/snapshot_dev_git/crashmonkey-PM$ git push remotes/origin/snapshot_dev
warning: push.default is unset; its implicit value has changed in
Git 2.0 from 'matching' to 'simple'. To squelch this message
and maintain the traditional behavior, use:

  git config --global push.default matching

To squelch this message and adopt the new behavior now, use:

  git config --global push.default simple

When push.default is set to 'matching', git will push local branches
to the remote branches that already exist with the same name.

Since Git 2.0, Git defaults to the more conservative 'simple'
behavior, which only pushes the current branch to the corresponding
remote branch that 'git pull' uses to update the current branch.

See 'git help config' and search for 'push.default' for further information.
(the 'simple' mode was introduced in Git 1.7.11. Use the similar mode
'current' instead of 'simple' if you sometimes use older versions of Git)

fatal: You are not currently on a branch.
To push the history leading to the current (detached HEAD)
state now, use

    git push remotes/origin/snapshot_dev HEAD:<name-of-remote-branch>

lillian@pandian-utcs:~/research/snapshot_dev_git/crashmonkey-PM$ git push remote/origin/snapshot_dev
warning: push.default is unset; its implicit value has changed in
Git 2.0 from 'matching' to 'simple'. To squelch this message
and maintain the traditional behavior, use:

  git config --global push.default matching

To squelch this message and adopt the new behavior now, use:

  git config --global push.default simple

When push.default is set to 'matching', git will push local branches
to the remote branches that already exist with the same name.

Since Git 2.0, Git defaults to the more conservative 'simple'
behavior, which only pushes the current branch to the corresponding
remote branch that 'git pull' uses to update the current branch.

See 'git help config' and search for 'push.default' for further information.
(the 'simple' mode was introduced in Git 1.7.11. Use the similar mode
'current' instead of 'simple' if you sometimes use older versions of Git)

fatal: You are not currently on a branch.
To push the history leading to the current (detached HEAD)
state now, use

    git push remote/origin/snapshot_dev HEAD:<name-of-remote-branch>

lillian@pandian-utcs:~/research/snapshot_dev_git/crashmonkey-PM$ cd personal_plugins/panda/plugins/writetracker/
lillian@pandian-utcs:~/research/snapshot_dev_git/crashmonkey-PM/personal_plugins/panda/plugins/writetracker$ vim writetracker.cpp 

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <memory>
#include <map>

#include "panda/plugin.h"

static target_ulong range_start;
static target_ulong range_end;

static std::ofstream ofs;

static std::unique_ptr<std::ofstream> output;
using namespace std;

enum event_type : int {
  WRITE,
  FLUSH,
  FENCE,
};


// ******* New code:

struct write_data_st {
    char * data;
    bool is_flushed;
};

std::map<char *, write_data_st*> snapshot_map;

// **********

static void log_output(target_ulong pc, event_type type, target_ulong offset, target_ulong write_size, void* write_data) {
  output->write(reinterpret_cast<char*>(&pc), sizeof(pc));
  output->write(reinterpret_cast<char*>(&type), sizeof(type));
  switch (type) {
  case WRITE: {

    // ******* New code:
"writetracker.cpp" 257L, 7697C                                                                                                               3,1           Top

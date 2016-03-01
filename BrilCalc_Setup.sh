setenv PATH $HOME/.local/bin:/afs/cern.ch/cms/lumi/brilconda-1.0.3/bin:$PATH
#pip uninstall -y brilws
#pip install --install-option="--prefix=$HOME/.local" brilws
pip show brilws
echo "brilcalc lumi --normtag /afs/cern.ch/user/c/cmsbril/public/normtag_json/OfflineNormtagV1.json -i JsonFile -u /fb"

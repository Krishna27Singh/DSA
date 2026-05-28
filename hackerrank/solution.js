'use strict';

function solve(rootName, jsonText) {
    let data;
    try {
        data = JSON.parse(jsonText);
    } catch (e) {
        // console.log("parse error", e)
        return "";
    }

    class Loc {
        constructor(k) {
            this.key = k;
            this.prim = new Set();
            this.objNode = null;
            this.arrLoc = null;
        }

        push(val) {
            if (val === null) {
                this.prim.add('null');
            } else if (typeof val === 'string') {
                this.prim.add('string');
            } else if (typeof val === 'number') {
                this.prim.add('number');
            } else if (typeof val === 'boolean') {
                this.prim.add('boolean');
            } else if (Array.isArray(val)) {
                if (!this.arrLoc) this.arrLoc = new Loc(this.key);
                for (let x of val) this.arrLoc.push(x);
            } else if (typeof val === 'object') {
                if (!this.objNode) this.objNode = new Node(this.key);
                this.objNode.push(val);
            }
        }

        getTypes() {
            let res = [];
            if (this.objNode && this.objNode.finalName) res.push(this.objNode.finalName);
            for (let p of this.prim) res.push(p);
            
            if (this.arrLoc) {
                let arrT = this.arrLoc.getTypes();
                if (arrT.length === 0) {
                    res.push('unknown[]');
                } else if (arrT.length === 1) {
                    res.push(arrT[0] + '[]');
                } else {
                    arrT.sort(); 
                    res.push('(' + arrT.join(' | ') + ')[]');
                }
            }
            return res;
        }
    }

    class Node {
        constructor(k) {
            this.key = k;
            this.count = 0;
            this.props = new Map();
            this.finalName = null;
        }

        push(obj) {
            this.count++;
            let keys = Object.keys(obj);
            for (let i = 0; i < keys.length; i++) {
                let k = keys[i];
                if (!this.props.has(k)) {
                    this.props.set(k, { c: 0, loc: new Loc(k) });
                }
                let p = this.props.get(k);
                p.c++;
                p.loc.push(obj[k]);
            }
        }
    }

    let root = new Node(rootName);
    for (let i = 0; i < data.length; i++) {
        root.push(data[i]);
    }

    let used = new Set([rootName]);
    let allNodes = [root];
    root.finalName = rootName;

    function getName(b) {
        if (!used.has(b)) {
            used.add(b);
            return b;
        }
        let idx = 2;
        while (used.has(b + idx)) {
            idx++;
        }
        let newName = b + idx;
        used.add(newName);
        return newName;
    }

    function assign(loc) {
        if (loc.objNode && !loc.objNode.finalName) {
            let b = loc.key.length > 0 ? loc.key[0].toUpperCase() + loc.key.slice(1) : "Empty";
            loc.objNode.finalName = getName(b);
            allNodes.push(loc.objNode);
            dfs(loc.objNode);
        }
        if (loc.arrLoc) {
            assign(loc.arrLoc);
        }
    }

    function dfs(n) {
        let keys = Array.from(n.props.keys()).sort();
        for (let i = 0; i < keys.length; i++) {
            assign(n.props.get(keys[i]).loc);
        }
    }

    dfs(root);

    allNodes.sort((a, b) => {
        if (a.finalName < b.finalName) return -1;
        if (a.finalName > b.finalName) return 1;
        return 0;
    });

    let out = [];
    for (let i = 0; i < allNodes.length; i++) {
        let n = allNodes[i];
        if (n.props.size === 0) {
            out.push(`export interface ${n.finalName} {}`);
        } else {
            let lines = [`export interface ${n.finalName} {`];
            let keys = Array.from(n.props.keys()).sort();
            
            for (let j = 0; j < keys.length; j++) {
                let k = keys[j];
                let p = n.props.get(k);
                
                let opt = p.c < n.count ? '?' : '';
                let types = p.loc.getTypes();
                types.sort(); 
                
                let tStr = types.length > 0 ? types.join(' | ') : 'unknown';
                lines.push(`  ${k}${opt}: ${tStr};`);
            }
            lines.push(`}`);
            out.push(lines.join('\n'));
        }
    }

    return out.join('\n\n');
}

function main() {
    const lines = require('fs').readFileSync(0, 'utf8').split('\n');
    if (!lines[0]) return;
    
    const t = parseInt(lines[0], 10);
    
    const blocks = [];
    for (let i = 0; i < t; i++) {
        const rootName = lines[1 + 2 * i].trim();
        const jsonText = lines[2 + 2 * i].trim();
        blocks.push(solve(rootName, jsonText));
    }
    
    process.stdout.write(blocks.join('\n---\n') + '\n');
}

main();
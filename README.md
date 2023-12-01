# arc-02-my_blockchain
<div class="card-block">
<div class="row">
<div class="col tab-content">
<div class="tab-pane active show" id="subject" role="tabpanel">
<div class="row">
<div class="col-md-12 col-xl-12">
<div class="markdown-body">
<p class="text-muted m-b-15">
</p><h1>My Blockchain</h1>
<p>Remember to git add &amp;&amp; git commit &amp;&amp; git push each exercise!</p>
<p>We will execute your function with our test(s), please DO NOT PROVIDE ANY TEST(S) in your file</p>
<p>For each exercise, you will have to create a folder and in this folder, you will have additional files that contain your work. Folder names are provided at the beginning of each exercise under <code>submit directory</code> and specific file names for each exercise are also provided at the beginning of each exercise under <code>submit file(s)</code>.</p>
<hr>
<table>
<thead>
<tr>
<th>My Blockchain</th>
<th></th>
</tr>
</thead>
<tbody>
<tr>
<td>Submit directory</td>
<td>.</td>
</tr>
<tr>
<td>Submit files</td>
<td>Makefile - *.c - *.h</td>
</tr>
</tbody>
</table>
<h3>Description</h3>
<h2>Command Name</h2>
<p><code>my_blockchain</code></p>
<h2>Blockchain: the Beginning</h2>
<p>my_blockchain -- create a blockchain</p>
<h2>Synopsis</h2>
<p>my_blockchain</p>
<h2>Description</h2>
<p>Blockchain is a command that allows for the creation and management of a blockchain. When the program starts (it loads a backup if there is one) then a prompt appears.
This prompt allows to execute commands. When the commands are successful they display "<strong>ok</strong>" and if not, "<strong>nok: <em>info</em></strong>" or <em>info</em> is an error message - see below:</p>
<ul>
<li>
<strong>add node <em>nid</em></strong> add a <em>nid</em> identifier to the blockchain node.</li>
<li>
<strong>rm node <em>nid...</em></strong> remove nodes from the blockchain with a <em>nid</em> identifier. If <strong>nid</strong> is '*', then all nodes are impacted.</li>
<li>
<strong>add block <em>bid</em> <em>nid...</em></strong> add a <em>bid</em> identifier block to nodes identified by <em>nid</em>. If <strong>nid</strong> is '*', then all nodes are impacted.</li>
<li>
<strong>rm block <em>bid...</em></strong> remove the <em>bid</em> identified blocks from all nodes where these blocks are present.</li>
<li>
<strong>ls</strong> list all nodes by their identifiers. The option <strong>-l</strong> attaches the blocks bid's associated with each node.</li>
<li>
<strong>sync</strong> synchronize all of the nodes with each other. Upon issuing this command, all of the nodes are composed of the same blocks.</li>
<li>
<strong>quit</strong> save and leave the blockchain.</li>
</ul>
<p>The blockchain prompt must display (see example below):</p>
<ul>
<li>a <strong>[</strong> character</li>
<li>a first letter that indicates the state of synchronization of the chain:
<ul>
<li>"<strong>s</strong>" if the blockchain is synchronized</li>
<li>"<strong>-</strong>" if the blockchain is not synchronized.</li>
</ul>
</li>
<li>
<strong>n</strong> number of nodes in the chain.</li>
<li>the "<strong>]&gt;</strong> " string (with a space)</li>
</ul>
<h2>Error messages</h2>
<ul>
<li>1: no more resources available on the computer</li>
<li>2: this node already exists</li>
<li>3: this block already exists</li>
<li>4: node doesn't exist</li>
<li>5: block doesn't exist</li>
<li>6: command not found</li>
</ul>
<h2>Technical Information</h2>
<pre class=" language-shell"><code class=" language-shell">$<span class="token operator">&gt;</span>my_blockhain
No Backup Found: Starting New Blockchain
<span class="token punctuation">[</span>s0<span class="token punctuation">]</span><span class="token operator">&gt;</span> add node 12
OK
<span class="token punctuation">[</span>s1<span class="token punctuation">]</span><span class="token operator">&gt;</span> add block 21 *
OK
<span class="token punctuation">[</span>s1<span class="token punctuation">]</span><span class="token operator">&gt;</span> add node 13
OK
<span class="token punctuation">[</span>-2<span class="token punctuation">]</span><span class="token operator">&gt;</span> <span class="token function">sync</span>
OK
<span class="token punctuation">[</span>s2<span class="token punctuation">]</span><span class="token operator">&gt;</span> <span class="token function">ls</span> -l
12: 21
13: 21
<span class="token punctuation">[</span>s2<span class="token punctuation">]</span><span class="token operator">&gt;</span> quit
Backing up blockchain<span class="token punctuation">..</span>.
</code></pre>
<pre class=" language-shell"><code class=" language-shell">$<span class="token operator">&gt;</span>my_blockhain
Restoring From Backup
<span class="token punctuation">[</span>s2<span class="token punctuation">]</span><span class="token operator">&gt;</span> <span class="token function">ls</span> -l
12: 21
13: 21
<span class="token punctuation">[</span>s2<span class="token punctuation">]</span><span class="token operator">&gt;</span>
</code></pre>
<ol>
<li>you must create a Makefile, and the output is the command itself</li>
<li>NID is an integer, BID is a string</li>
<li>You can use:</li>
</ol>
<ul>
<li>
<p>• malloc(3)</p>
</li>
<li>
<p>• free(3)</p>
</li>
<li>
<p>• printf(3)</p>
</li>
<li>
<p>• write(2)</p>
</li>
<li>
<p>• open(2)</p>
</li>
<li>
<p>• read(2)</p>
</li>
<li>
<p>• close(2)</p>
</li>
<li>
<p>Multiline macros are forbidden</p>
</li>
<li>
<p>Include another .c is forbidden</p>
</li>
<li>
<p>Macros with logic (while/if/variables/...) are forbidden</p>
</li>
</ul>

<p></p>
</div>

</div>
</div>
</div>
<div class="tab-pane" id="resources" role="tabpanel">
</div>
</div>
</div>
</div>

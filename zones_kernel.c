#include <linux/module.h>
#include <linux/init.h>
#include <linux/mmzone.h>
#include <linux/mm.h>
#include <linux/node.h>

static int __init zones_init(void)
{
    int nid, zid;
    struct zone *zone;
    struct pglist_data *pgdat;

    pr_info("=== MEMORY ZONES INFO ===\n");

    for_each_online_node(nid) {

        pgdat = NODE_DATA(nid);
        pr_info("Node %d:\n", nid);

        for (zid = 0; zid < MAX_NR_ZONES; zid++) {

            zone = &pgdat->node_zones[zid];

            if (!populated_zone(zone))
                continue;

            pr_info("  Zone: %s\n", zone->name);
            pr_info("    Managed pages: %lu\n",
                    zone_managed_pages(zone));
        }
    }

    return 0;
}

static void __exit zones_exit(void)
{
    pr_info("Zones module unloaded\n");
}

module_init(zones_init);
module_exit(zones_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Amit Joshi");
MODULE_DESCRIPTION("Kernel Module to Print Memory Zones");
